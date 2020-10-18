#define PLAY "kill -USR2 $(pgrep playerctl_title)"
#define PAUSE "kill -USR2 $(pgrep playerctl_title)"
#define PREVIOUS "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotifyd /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous"
#define NEXT "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotifyd /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next"

#define MAIN main
#define MUSIC music
#define MIC alsa_input.hw_3_1_0

#define STR(X) #X

#define CONNECT(SINK,DEVICE) \
	system("/home/gabriel/.local/bin/jack_pulse connect " STR(SINK) " " STR(DEVICE))

#define DISCONNECT(SINK,DEVICE) \
	system("/home/gabriel/.local/bin/jack_pulse disconnect " STR(SINK) " " STR(DEVICE))

#define DROIDCAM(TYPE) \
	system("/home/gabriel/.local/bin/droidcamcli " STR(TYPE))

#define VOL(TYPE,NAME)			\
	char a[4];				\
	char cmd[100];				\
	if(led <= 100){			\
		sprintf(a, "%d", led);	\
		strcat(strcpy(cmd, "/home/gabriel/.local/bin/pulse_vol " STR(TYPE) " "  STR(NAME) " "), a); \
		system(cmd);			\
	}

keys buttons[37] = {
/* Key	Midi Value		Function					Key name		Location	  */
/*  0 */	{	-1,			&noFunc			}, /*	Search <<<	Deck A	  */	
/*  1 */	{	-1,			&noFunc			}, /*	Search >>>	Deck A	  */
/*  2 */	{	-1,			&noFunc			}, /*	Bend -		Deck A	  */
/*  3 */	{	-1,			&noFunc			}, /*	Bend +		Deck A	  */
/*  4 */	{	-1,			&noFunc			}, /*	Set Cue		Deck A	  */
/*  5 */	{	21,			&noFunc			}, /*	Reloop		Deck A	  */
/*  6 */	{	-1,			&nextSong			}, /*	Search <<<	Deck B	  */
/*  7 */	{	-1,			&previousSong		}, /*	Search >>>	Deck B	  */
/*  8 */	{	-1,			&noFunc			}, /*	Bend -		Deck B	  */
/*  9 */	{	-1,			&noFunc			}, /*	Bend +		Deck B	  */
/* 10 */	{	-1,			&noFunc			}, /*	Set Cue		Deck B	  */
/* 11 */	{	13,			&noFunc			}, /*	Reloop		Deck B	  */
/* 12 */	{	24,			&mainMaster		}, /*	Low Kill		Deck A	  */
/* 13 */	{	23,			&mainPhone		}, /*	Mid Kill		Deck A	  */
/* 14 */	{	22,			&noFunc			}, /*	High Kill		Deck A	  */
/* 15 */	{	-1,			&noFunc			}, /*	Set Cue		Deck A	  */
/* 16 */	{	20,			&noFunc			}, /*	Sync			Deck A	  */
/* 17 */	{	19,			&noFunc			}, /*	Scratch		Deck A	  */
/* 18 */	{	18,			&noFunc			}, /*	Play			Deck A	  */
/* 19 */	{	17,			&noFunc			}, /*	Cue			Deck A	  */
/* 20 */	{	16,			&musicMaster		}, /*	Low Kill		Deck B	  */
/* 21 */	{	15,			&musicPhone		}, /*	Mid Kill		Deck B	  */
/* 22 */	{	14,			&noFunc			}, /*	High Kill		Deck B	  */
/* 23 */	{	-1,			&noFunc			}, /*	Set loop		Deck B	  */
/* 24 */	{	12,			&noFunc			}, /*	Sync			Deck B	  */
/* 25 */	{	11,			&noFunc			}, /*	Scratch		Deck B	  */
/* 26 */	{	10,			&pauseSpotify		}, /*	Play			Deck B	  */
/* 27 */	{	 9,			&noFunc			}, /*	Cue			Deck B	  */
/* 28 */	{	25,			&connectDroidcam	}, /*	Key Deck A+B	Deck A+B	  */
/* 29 */	{	 8,			&noFunc			}, /*	EXT IN A		Input Select*/
/* 30 */	{	 7,			&noFunc			}, /*	EXT IN B		Input Select*/
/* 31 */	{	 6,			&noFunc			}, /*	ON			FX Control  */
/* 32 */	{	 5,			&noFunc			}, /*	FXv			FX Control  */
/* 33 */	{	 4,			&noFunc			}, /*	FX^			FX Control  */
/* 34 */	{	 3,			&noFunc			}, /*	Action		FX Control  */
/* 35 */	{	 2,			&noFunc			}, /*	Cue A		Cue Select  */
/* 36 */	{	 1,			&noFunc			}, /*	Cue B		Cue Select  */
};

knobFunc knobs[20] = { 
	&mainVolume, 	//0		Volume Fader	Deck	A
	&noFunc,	   	//1		Cross Fader	Deck A+B
	&musicVolume,	//2		Volume Fader	Deck B
	&noFunc,		//3		Low Eq		Deck A
	&noFunc,		//4		Mid Eq		Deck A
	&noFunc,		//5		High Eq		Deck A
	&noFunc,		//6		Gain			Deck A
	&noFunc,		//7		Low Eq		Deck B
	&noFunc,		//8		Mid Eq		Deck B
	&noFunc,		//9		High Eq		Deck B
	&noFunc,		//10		Gain			Deck B
	&noFunc,		//11		Pitch Fader	Deck A
	&noFunc,		//12		Pitch Fader	Deck B
	&noFunc,		//13		Data 4		Fx Control
	&noFunc,		//14		Data 4		Fx Control
	&noFunc,		//15		Data 4		Fx Control
	&noFunc,		//16		Data 4		Fx Control
	&micVolume,	//17		Phones Mix	Output
	&noFunc,		//18		Scratch Wheel	Deck B
	&noFunc,		//19		Scratch Wheel	Deck A
};
