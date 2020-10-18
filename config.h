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
	/*Midi Value		Function		Led Status */	   /*Key	  Key name	Location	  */
	{	-1,			&noFunc,			0	 },	   /* 0	  Search <<<	Deck A	  */	
	{	-1,			&noFunc,			0	 },	   /* 1	  Search >>>	Deck A	  */
	{	-1,			&noFunc,			0	 },	   /* 2	  Bend -		Deck A	  */
	{	-1,			&noFunc,			0	 },	   /* 3	  Bend +		Deck A	  */
	{	-1,			&noFunc,			0	 },	   /* 4	  Set Cue		Deck A	  */
	{	21,			&noFunc,			0	 },	   /* 5	  Reloop		Deck A	  */
	{	-1,			&nextSong,		0	 },	   /* 6	  Search <<<	Deck B	  */
	{	-1,			&previousSong,		0	 },	   /* 7	  Search >>>	Deck B	  */
	{	-1,			&noFunc,			0	 },	   /* 8	  Bend -		Deck B	  */
	{	-1,			&noFunc,			0	 },	   /* 9	  Bend +		Deck B	  */
	{	-1,			&noFunc,			0	 },	   /* 10	  Set Cue		Deck B	  */
	{	13,			&noFunc,			0	 },	   /* 11	  Reloop		Deck B	  */
	{	24,			&mainMaster,		0	 },	   /* 12	  Low Kill	Deck A	  */
	{	23,			&mainPhone,		0	 },	   /* 13	  Mid Kill	Deck A	  */
	{	22,			&noFunc,			0	 },	   /* 14	  High Kill	Deck A	  */
	{	-1,			&noFunc,			0	 },	   /* 15	  Set Cue		Deck A	  */
	{	20,			&noFunc,			0	 },	   /* 16	  Sync		Deck A	  */
	{	19,			&noFunc,			0	 },	   /* 17	  Scratch		Deck A	  */
	{	18,			&noFunc,			0	 },	   /* 18	  Play		Deck A	  */
	{	17,			&noFunc,			0	 },	   /* 19	  Cue		Deck A	  */
	{	16,			&musicMaster,		0	 },	   /* 20	  Low Kill	Deck B	  */
	{	15,			&musicPhone,		0	 },	   /* 21	  Mid Kill	Deck B	  */
	{	14,			&noFunc,			0	 },	   /* 22	  High Kill	Deck B	  */
	{	-1,			&noFunc,			0	 },	   /* 23	  Set loop	Deck B	  */
	{	12,			&noFunc,			0	 },	   /* 24	  Sync		Deck B	  */
	{	11,			&noFunc,			0	 },	   /* 25	  Scratch		Deck B	  */
	{	10,			&pauseSpotify,		0	 },	   /* 26	  Play		Deck B	  */
	{	 9,			&noFunc,			0	 },	   /* 27	  Cue		Deck B	  */
	{	25,			&connectDroidcam,	0	 },	   /* 28	  Key Deck A+B	Deck A+B	  */
	{	 8,			&noFunc,			0	 },	   /* 29	  EXT IN A	Input Select*/
	{	 7,			&noFunc,			0	 },	   /* 30	  EXT IN B	Input Select*/
	{	 6,			&noFunc,			0	 },	   /* 31	  ON			FX Control  */
	{	 5,			&noFunc,			0	 },	   /* 32	  FXv		FX Control  */
	{	 4,			&noFunc,			0	 },	   /* 33	  FX^		FX Control  */
	{	 3,			&noFunc,			0	 },	   /* 34	  Action		FX Control  */
	{	 2,			&noFunc,			0	 },	   /* 35	  Cue A		Cue Select  */
	{	 1,			&noFunc,			0	 },	   /* 36	  Cue B		Cue Select  */
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
