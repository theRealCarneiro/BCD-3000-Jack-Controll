typedef void (*keyFunc) (char);

typedef void (*knobFunc) (char);

typedef struct keys {
	int ledKey;
	keyFunc function;
	int ledStatus;
} keys;

void *threadFunc(void *args);

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

void connectDroidcam(char led);

void noFunc(char led);

