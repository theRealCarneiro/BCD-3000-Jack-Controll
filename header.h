#include <alsa/asoundlib.h>
#include <alsa/control.h>

#define PLAY "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Play"
#define PAUSE "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Pause"
#define PREVIOUS "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous"
#define NEXT "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next"

int midiValues[37] = { //-1 equals no led
	-1, -1, -1, -1, -1,
	21, -1, -1, -1, -1,
	-1, 13, 24, 23, 22,
	-1, 20, 19, 18, 17,
	16, 15, 14, -1, 12,
	11, 10, 9, 25, 8, 7,
	6, 5, 4,  3, 2, 1
 };

int ledStatus[37] = {0};

void startMidi(const char* portname); //Starts the midi conection

int getMidiInput(char buffer[1], int status, snd_rawmidi_t *midiin, snd_rawmidi_t *midiout); //Reads the signal from the BCD

void errormessage(const char *format, ...);

void master(int status, int channel);

void phone(int status, int channel);

void midiJack(int key, int led);

void volume(char noteon[3]);
