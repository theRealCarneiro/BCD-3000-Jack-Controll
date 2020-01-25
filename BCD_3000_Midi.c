
#include <stdlib.h>
#include <string.h>
#include "header.h"

/*int midiValues[37] = { //-1 equals no led
	-1, -1, -1, -1, -1,
	21, -1, -1, -1, -1,
	-1, 13, 24, 23, 22,
	-1, 20, 19, 18, 17,
	16, 15, 14, -1, 12,
	11, 10, 9, 25, 8, 7,
	6, 5, 4,  3, 2, 1
 };

int ledStatus[37] = {0};
*/

int main (int argc, char *argv[]){
	system("amidi -l | grep BCD | cut -c5-12 >> hw.txt");
     FILE *fp;
     char hw[10];
     int i = 0;
	fp = fopen("hw.txt","rt");
	while((hw[i] = fgetc(fp)) != EOF) i++;
	hw[8] = '\0';
	fclose(fp);
	remove("hw.txt");

	int status;
	const char* portname = hw;
	if(argc > 1){
		startMidi(argv[1]);
	}
	else startMidi(portname);
}

void startMidi(const char* portname){ //Starts the midi conection
	int status;
	int mode = SND_RAWMIDI_SYNC;
	snd_rawmidi_t *midiin = NULL;
	snd_rawmidi_t *midiout = NULL;
	if ((status = snd_rawmidi_open(&midiin, &midiout, portname, mode)) < 0){
		errormessage("Problem opening MIDI input: %s", snd_strerror(status));
		exit(1);
	}

	char buffer[1];      // Storage for input buffer received
	while(1){
		getMidiInput(buffer, status, midiin, midiout);
	}
}

int getMidiInput(char buffer[1], int status, snd_rawmidi_t *midiin, snd_rawmidi_t *midiout){
	int i = 0;
	int buttonPressed = 0;
	char noteon[3]; //ex: {0xB0, 17, 127};
	int key;

	while (i < 3){
          //Reads the midi signal from the BCD
		if ((status = snd_rawmidi_read(midiin, buffer, 1)) < 0){
			errormessage("Problem reading MIDI input: %s", snd_strerror(status));
		}

		if(i == 0){ //Hex code for the type of message
			if ((unsigned char)buffer[0] == 0x90){ // button press
				buttonPressed = 1;
			}
			else {
				buttonPressed = 0;
				noteon[0] = 0xB0;
			}
		}

		else if (i == 1){ //This is the note value of the pressed button
			key = (int)buffer[0];
			if(buttonPressed == 1){
				noteon[1] = midiValues[key];
			}
			else noteon[1] = key;
		}

          //buffer = 127 = button pressed, buffer = 0 = button released
		else if(i == 2){
			if(buttonPressed == 0){
				noteon[2] = (int)buffer[0]; //Volume level
				volume(noteon);
			}
			else {
				if((int)buffer[0] == 127) {
					if(ledStatus[key] == 0){
						ledStatus[key] = 127;
						noteon[2] = 127;
					}
					else if(ledStatus[key] == 127){
						ledStatus[key] = 0;
						noteon[2] = 0;
					}
					midiJack(key, noteon[2]);
				}
			}
		}
		fflush(stdout);
		i++;
	}

	if(buttonPressed == 1 && noteon[1] != -1) { //Led == 1 means that it is a button, key = -1 means that the button doesnt have a led
		if ((status = snd_rawmidi_write(midiout, noteon, 3)) < 0) { //Sends the midi signal to the BCD
			errormessage("Problem writing to MIDI output: %s", snd_strerror(status));
			exit(1);
		}
	}
}

void errormessage(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	putc('\n', stderr);
}
