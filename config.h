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
	-1, //0
	-1, //1
	-1, //2
	-1, //3
	-1, //4
	21, //5
	-1, //6
	-1, //7
	-1, //8
	-1, //9
	-1, //10
	13, //11
	24, //12
	23, //13
	22, //14
	-1, //15
	20, //16
	19, //17
	18, //18
	17, //19
	16, //20
	15, //21
	14, //22
	-1, //23
	12, //24
	11, //25
	10, //26
	 9, //27
	25, //28
	 8, //29
	 7, //30
	 6, //31
	 5, //32
	 4, //33 
	 3, //34
	 2, //35
	 1  //36
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
