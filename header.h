#include <alsa/asoundlib.h>
#include <alsa/control.h>

typedef void (*keyFunc) (char);

void errormessage(const char *format, ...);

void openMidi(const char* portname);

int readMidi(char buffer[3]);

void writeMidi(char noteon[3]);

void mainVolume(char led);

void musicVolume(char led);

void micVolume(char led);

void mainMaster(char led);

void mainPhone(char led);

void musicMaster(char led);

void musicPhone(char led);

void pauseSpotify(char led);

void nextSong(char led);

void previousSong(char led);

void connectDroidCam(char led);

void noFunc(char led);

