#include <alsa/asoundlib.h>
#include <alsa/control.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include "header.h"
#include "config.h"

int status;
int mode = SND_RAWMIDI_SYNC;
snd_rawmidi_t *midiin = NULL;
snd_rawmidi_t *midiout = NULL;

void main(){

	FILE *fp;
	char hw[10];
	fp = popen("/usr/bin/amidi -l | /usr/bin/awk '/BCD/{print $2}'", "r"); 
	if (fp == NULL) {
		fprintf(stderr, "Failed to run command\n");
		exit(1);
	}
	fgets(hw, sizeof(hw)-1, fp);
	pclose(fp);

	const char *portname = hw;
	char noteon[3];
	char buffer[3];
	pthread_t midiinthread;
	openMidi(portname);
	while(1){
		int key = readMidi(buffer); //reads midi and return key
		noteon[1] = buttons[key].ledKey;
		if((unsigned char)buffer[0] == 0x90 && noteon[1] != -1){ //0x90 == button 0xB0 == knob
			noteon[0] = 0xB0;
			noteon[2] = buffer[2] = buttons[key].ledStatus = 127 - buttons[key].ledStatus; //toggle led
			writeMidi(noteon);
		}

		status = pthread_create(&midiinthread, NULL, threadFunc, (void*)buffer);
		if (status == -1) {
			errormessage("Unable to create MIDI input thread.");
			exit(1);
		}
	}
}

void *threadFunc(void *args){
	char *noteon = (char*)args;
	int key = (int)noteon[1];
	if((unsigned char)noteon[0] == 0x90) //0x90 == button 0xB0 == knob
		buttons[key].function(noteon[2]);
	else 
		knobs[key](noteon[2]);

	pthread_exit(NULL);
	//printf("%x %d %d\n",(unsigned char)noteon[0], (int)noteon[1], (int)noteon[2]); //to print info
}

void errormessage(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	putc('\n', stderr);
}

void openMidi(const char* portname){
	if ((status = snd_rawmidi_open(&midiin, &midiout, portname, mode)) < 0){
		errormessage("Problem opening MIDI input: %s", snd_strerror(status));
		exit(1);
	}
}

int readMidi(char buffer[3]){
	int key = 0;
	do {
		fflush(stdout);
		if ((status = snd_rawmidi_read(midiin, buffer, 3)) < 0){
			errormessage("Problem reading MIDI input: %s", snd_strerror(status));
		}
		key = (int)buffer[1];
	} while(((int)buffer[2] != 127 && (unsigned char)buffer[0] == 0x90));
	return key;
}


void writeMidi(char noteon[3]){
	if ((status = snd_rawmidi_write(midiout, noteon, 3)) < 0) { // Writes the signal 
		errormessage("Problem writing to MIDI output: %s", snd_strerror(status));
		exit(1);
	}
}

void mainVolume(char led){
	VOL(sink, MAIN)
}

void musicVolume(char led){
	VOL(sink, MUSIC)
}

void micVolume(char led){
	VOL(source,MIC)
}

void mainMaster(char led){
	led ? CONNECT(main,master) : DISCONNECT(main,master);
}

void mainPhone(char led){
	led ? CONNECT(main,phone) : DISCONNECT(main,phone);
}

void musicMaster(char led){
	led ? CONNECT(music,master) : DISCONNECT(music,master);
}

void musicPhone(char led){
	led ? CONNECT(music,phone) : DISCONNECT(music,phone);
}

void pauseSpotify(char led){
	system(led ? PLAY : PAUSE); 
}

void nextSong(char led){
	system(PREVIOUS);
}

void previousSong(char led){
	system(NEXT);
}

void connectDroidcam(char led){
	DROIDCAM(audio);
}

void noFunc(char led){
	return;
}
