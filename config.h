#define PLAY "/home/gabriel/.local/bin/Polybar/play-pause"

#define MAIN main
#define MUSIC music
#define MIC alsa_input.hw_3_1_0

#define STR(X) #X

#define DROIDCAM(TYPE) \
	"/home/gabriel/.local/bin/droidcamcli " STR(TYPE)

#define CONNECT(SINK,DEVICE) \
	"/home/gabriel/.local/bin/jack_pulse connect " STR(SINK) " " STR(DEVICE)

#define DISCONNECT(SINK,DEVICE) \
	"/home/gabriel/.local/bin/jack_pulse disconnect " STR(SINK) " " STR(DEVICE)

#define VOL(TYPE,NAME) \
	"/home/gabriel/.local/bin/pulse_vol " STR(TYPE) " "  STR(NAME) " "


keys buttons[37] = {
/* Key		Led key	cmd_on				cmd_off					cmd_knob			*/
/*  0 */	{	-1,		"",					"",						VOL(sink, MAIN),	0	}, 	
/*  1 */	{	-1,		"",					"",						"",				0	}, 
/*  2 */	{	-1,		"",					"",						VOL(sink, MUSIC),	0	}, 
/*  3 */	{	-1,		"",					"",						"",				0	}, 
/*  4 */	{	-1,		"",					"",						"",				0	}, 
/*  5 */	{	21,		"",					"",						"",				0	}, 
/*  6 */	{	-1,		"",					"",						"",				0	}, 
/*  7 */	{	-1,		"",					"",						"",				0	}, 
/*  8 */	{	-1,		"",					"",						"",				0	}, 
/*  9 */	{	-1,		"",					"",						"",				0	}, 
/* 10 */	{	-1,		"",					"",						"",				0	}, 
/* 11 */	{	13,		"",					"",						"",				0	}, 
/* 12 */	{	24,		CONNECT(main,master),	DISCONNECT(main,master),		"",				0	}, 
/* 13 */	{	23,		CONNECT(main,phone),	DISCONNECT(main,phone),		"",				0	}, 
/* 14 */	{	22,		"",					"",						"",				0	}, 
/* 15 */	{	-1,		"",					"",						"",				0	}, 
/* 16 */	{	20,		"",					"",						"",				0	}, 
/* 17 */	{	19,		"",					"",						VOL(source, MIC),	0	}, 
/* 18 */	{	18,		"",					"",						"",				0	}, 
/* 19 */	{	17,		"",					"",						"",				0	}, 
/* 20 */	{	16,		CONNECT(music,master),	DISCONNECT(music,master),	"",				0	},
/* 21 */	{	15,		CONNECT(music,phone),	DISCONNECT(music,phone),		"",				0	}, 
/* 22 */	{	14,		"",					"",						"",				0	}, 
/* 23 */	{	-1,		"",					"",						"",				0	}, 
/* 24 */	{	12,		"",					"",						"",				0	}, 
/* 25 */	{	11,		"",					"",						"",				0	}, 
/* 26 */	{	10,		PLAY,				PLAY,					"",				0	}, 
/* 27 */	{	 9,		"",					"",						"",				0	}, 
/* 28 */	{	25,		DROIDCAM(audio),		DROIDCAM(audio),			"",				0	}, 
/* 29 */	{	 8,		"",					"",						"",				0	}, 
/* 30 */	{	 7,		"",					"",						"",				0	}, 
/* 31 */	{	 6,		"",					"",						"",				0	}, 
/* 32 */	{	 5,		"",					"",						"",				0	}, 
/* 33 */	{	 4,		"",					"",						"",				0	}, 
/* 34 */	{	 3,		"",					"",						"",				0	}, 
/* 35 */	{	 2,		"",					"",						"",				0	}, 
/* 36 */	{	 1,		"",					"",						"",				0	}, 
};

/* Key  	Key name		Location	  Knob			Location	*/  
/*  0 	Search <<<	Deck A	  Volume Fader		Deck	A	*/
/*  1 	Search >>>	Deck A	  Cross Fader		Deck A+B	*/
/*  2 	Bend -		Deck A	  Volume Fader		Deck B	*/
/*  3 	Bend +		Deck A	  Low Eq			Deck A	*/
/*  4 	Set Cue		Deck A	  Mid Eq			Deck A	*/
/*  5 	Reloop		Deck A	  High Eq			Deck A	*/
/*  6 	Search <<<	Deck B	  Gain			Deck A	*/
/*  7 	Search >>>	Deck B	  Low Eq			Deck B	*/
/*  8 	Bend -		Deck B	  Mid Eq			Deck B	*/
/*  9 	Bend +		Deck B	  High Eq			Deck B	*/
/* 10 	Set Cue		Deck B	  Gain			Deck B	*/
/* 11 	Reloop		Deck B	  Pitch Fader		Deck A	*/
/* 12 	Low Kill		Deck A	  Pitch Fader		Deck B	*/
/* 13 	Mid Kill		Deck A	  Data 4			Fx Control*/
/* 14 	High Kill		Deck A	  Data 4			Fx Control*/
/* 15 	Set Cue		Deck A	  Data 4			Fx Control*/
/* 16 	Sync			Deck A	  Data 4			Fx Control*/
/* 17 	Scratch		Deck A	  Phones Mix		Output	*/
/* 18 	Play			Deck A	  Scratch Wheel	Deck B	*/
/* 19 	Cue			Deck A	  Scratch Wheel	Deck A	*/
/* 20 	Low Kill		Deck B	  */
/* 21 	Mid Kill		Deck B	  */
/* 22 	High Kill		Deck B	  */
/* 23 	Set loop		Deck B	  */
/* 24 	Sync			Deck B	  */
/* 25 	Scratch		Deck B	  */
/* 26 	Play			Deck B	  */
/* 27 	Cue			Deck B	  */
/* 28 	Key Deck A+B	Deck A+B	  */
/* 29 	EXT IN A		Input Select*/
/* 30 	EXT IN B		Input Select*/
/* 31 	ON			FX Control  */
/* 32 	FXv			FX Control  */
/* 33 	FX^			FX Control  */
/* 34 	Action		FX Control  */
/* 35 	Cue A		Cue Select  */
/* 36 	Cue B		Cue Select  */
