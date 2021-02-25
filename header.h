#include <alsa/asoundlib.h>
#include <alsa/control.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

typedef void (*keyFunc) (char);

typedef void (*knobFunc) (char);

typedef struct keys {
	int led_key;
	const char *cmd_on;
	const char *cmd_off;
	const char *knob_cmd;
	int led_status;
} keys;

void *threadFunc(void *args);

void errormessage(const char *format, ...);

void openMidi(const char* portname);

int readMidi(char buffer[3]);

void writeMidi(char noteon[3]);

void key_cmd(int key);

void knob_cmd(int key);
