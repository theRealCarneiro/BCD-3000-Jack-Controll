#define PLAY "kill -USR2 $(pgrep playerctl_title)"
#define PAUSE "kill -USR2 $(pgrep playerctl_title)"
//#define PLAY "/home/gabriel/.local/bin/Polybar/play-pause"
//#define PAUSE "/home/gabriel/.local/bin/Polybar/play-pause"
#define PREVIOUS "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotifyd /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous"
#define NEXT "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotifyd /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next"

#define MAIN main
#define MUSIC music
#define MIC alsa_input.hw_3_1_0
//#define MIC droidcam
//#define MIC alsa_input.pci-0000_00_1b.0.analog-stereo

#define STR(X) #X

#define CONNECT(SINK,DEVICE) system("/home/gabriel/.local/bin/jack_pulse connect " STR(SINK) " " STR(DEVICE))
#define DISCONNECT(SINK,DEVICE) system("/home/gabriel/.local/bin/jack_pulse disconnect " STR(SINK) " " STR(DEVICE))
#define DROIDCAM "/home/gabriel/.local/bin/droidcamcli audio"

#define VOL(TYPE,NAME)			\
	char a[4];				\
	char cmd[100];				\
	if(led <= 100){				\
		sprintf(a, "%d", led);	\
		strcat(strcpy(cmd, "/home/gabriel/.local/bin/pulse_vol " STR(TYPE) " "  STR(NAME) " "), a); \
		system(cmd);			\
	}

int midiValues[37] = { //-1 equals no led
	-1, //0	Search <<<	Deck A	Volume Fader	Deck	A
	-1, //1	Search >>>	Deck A	Cross Fader	Deck A+B
	-1, //2	Bend -		Deck A	Volume Fader	Deck B
	-1, //3	Bend +		Deck A
	-1, //4	Set Cue		Deck A
	21, //5	Reloop		Deck A
	-1, //6	Search <<<	Deck B
	-1, //7	Search >>>	Deck B
	-1, //8	Bend -		Deck B
	-1, //9	Bend +		Deck B
	-1, //10	Set Cue		Deck B
	13, //11	Reloop		Deck B	Pitch Fader	Deck A
	24, //12	Low Kill		Deck A	Pitch Fader	Deck B
	23, //13	Mid Kill		Deck A
	22, //14	High Kill		Deck A
	-1, //15	Set Cue		Deck A
	20, //16	Sync			Deck A
	19, //17	Scratch		Deck A
	18, //18  Play			Deck A
	17, //19  Cue			Deck A
	16, //20	Low Kill		Deck B
	15, //21	Mid Kill		Deck B
	14, //22	High Kill		Deck B 
	-1, //23  Set loop		Deck B
	12, //24	Sync			Deck B
	11, //25	Scratch		Deck B
	10, //26	Play			Deck B
	 9, //27	Cue			Deck B
	25, //28	Key Deck A+B	Deck A+N
	 8, //29	EXT IN A		Input Select
	 7, //30	EXT IN B		Input Select
	 6, //31	ON			FX Control
	 5, //32	FXv			FX Control
	 4, //33	FX^			FX Control
	 3, //34	Action		FX Control
	 2, //35	Cue A		Cue Select
	 1  //36	Cue B		Cue Select
 };

int ledStatus[37] = {0};

keyFunc buttons[37] = {
	&mainVolume,		//0
	&noFunc,			//1
	&musicVolume,		//2 
	&noFunc,			//3
	&noFunc,			//4 
	&noFunc,			//5
	&nextSong,		//6
	&previousSong,		//7 
	&noFunc,			//8 
	&noFunc,			//9
	&noFunc,			//10
	&noFunc,			//11
	&mainMaster,		//12 
	&mainPhone,		//13
	&noFunc,			//14
	&noFunc,			//15 
	&noFunc,			//16 
	&micVolume,		//17
	&noFunc,			//18
	&noFunc,			//19
	&musicMaster,		//20
	&musicPhone,		//21 
	&noFunc,			//22
	&noFunc,			//23
	&noFunc,			//24 
	&noFunc,			//25 
	&pauseSpotify,		//26
	&noFunc,			//27
	&connectDroidCam,	//28
	&noFunc,			//29
	&noFunc,			//30
	&noFunc,			//31
	&noFunc,			//32
	&noFunc,			//33
	&noFunc,			//34
	&noFunc,			//35
	&noFunc			//36
};
