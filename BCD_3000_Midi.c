#include <alsa/asoundlib.h>
#include <alsa/control.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"
#include "config.h"

int status;
int mode = SND_RAWMIDI_SYNC;
snd_rawmidi_t *midiin = NULL;
snd_rawmidi_t *midiout = NULL;

void main(){
	system("amidi -l | grep BCD | awk '{print $2}' > hw.txt");
     FILE *fp;
     char hw[10];
     int i = 0;
	fp = fopen("hw.txt","rt");
	while((hw[i] = fgetc(fp)) != EOF) i++;
	hw[8] = '\0';
	fclose(fp);
	remove("hw.txt");
	
	const char *portname = hw;
	char noteon[3];
	openMidi(portname);
	while(1){
		int key = readMidi(noteon);
		noteon[1] = midiValues[key];
		if(noteon[1] != -1 && (unsigned char)noteon[0] == 0x90){
			noteon[0] = 0xB0;
			noteon[2] = ledSwitch(key);
			writeMidi(noteon);
		}

		//printf("%x %d %d\n",(unsigned char)noteon[0], (int)noteon[1], (int)noteon[2]);
		buttons[key](noteon[2]);
	}
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

		//printf("%x %d %d\n",(unsigned char)buffer[0], (int)buffer[1], (int)buffer[2]);
	}
	while(((int)buffer[2] != 127 && 
		(unsigned char)buffer[0] == 0x90) ||
		(((unsigned char)buffer[0] != 0x90) && 
		(key == 18 || key == 19 || key == 12 || key == 11)));
	return key;
}


void writeMidi(char noteon[3]){
	if ((status = snd_rawmidi_write(midiout, noteon, 3)) < 0) { // Writes the signal 
		errormessage("Problem writing to MIDI output: %s", snd_strerror(status));
		exit(1);
	}
}

int ledSwitch(int key){
	if(ledStatus[key] == 0){
		ledStatus[key] = 127;
		return 127;
	} else {
		ledStatus[key] = 0;
		return 0;
	}
}

void mainVolume(char led){
	char a[4];
	char text[100];
	if(led < 100){
		sprintf(a, "%d", led);
		strcat(strcpy(text, MAINVOL), strcat(a, "%"));
		system(text);
	}
}

void musicVolume(char led){
	char a[4];
	char text[100];
	if(led < 100){
		sprintf(a, "%d", led);
		strcat(strcpy(text, MUSICVOL), strcat(a, "%"));
		system(text);
	}
}

void micVolume(char led){
	char a[4];
	char text[100];
	if(led < 100){
		sprintf(a, "%d", led);
		strcat(strcpy(text, MICVOL), strcat(a, "%"));
		system(text);
	}
}

void mainMaster(char led){
	if(led == 127){
		system(CONNECT_MAIN_MASTER);
	}
	else system(DISCONNECT_MAIN_MASTER);
}

void mainPhone(char led){
	if(led == 127){
		system(CONNECT_MAIN_PHONE);
	}
	else system(DISCONNECT_MAIN_PHONE);
}

void musicMaster(char led){
	if(led == 127){
		system(CONNECT_MUSIC_MASTER);
	}
	else system(DISCONNECT_MUSIC_MASTER);
}

void musicPhone(char led){
	if(led == 127){
		system(CONNECT_MUSIC_PHONE);
	}
	else system(DISCONNECT_MUSIC_PHONE);
}

void pauseSpotify(char led){
	if(led == 127){
		system(PLAY);
	} else system(PAUSE);
}

void nextSong(char led){
	system(PREVIOUS);
}

void previousSong(char led){
	system(NEXT);
}

void noFunc(char led){
	return;
}



