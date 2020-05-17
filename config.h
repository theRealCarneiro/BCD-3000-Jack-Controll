#define PLAY "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Play"
#define PAUSE "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Pause"
#define PREVIOUS "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous"
#define NEXT "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next"

#define MAINVOL "pactl set-sink-volume jack_out "
#define MUSICVOL "pactl set-sink-volume jack_out.2 "
#define MICVOL "pactl set-source-volume alsa_input.pci-0000_00_1b.0.analog-stereo "

#define CONNECT_MUSIC_MASTER "jack_connect music:front-left system:playback_1 & jack_connect music:front-right system:playback_2"
#define CONNECT_MUSIC_PHONE "jack_connect music:front-left system:playback_3 & jack_connect music:front-right system:playback_4"
#define DISCONNECT_MUSIC_MASTER "jack_disconnect music:front-left system:playback_1 & jack_disconnect music:front-right system:playback_2"
#define DISCONNECT_MUSIC_PHONE "jack_disconnect music:front-left system:playback_3 & jack_disconnect music:front-right system:playback_4"

#define CONNECT_MAIN_MASTER "jack_connect main:front-left system:playback_1 & jack_connect main:front-right system:playback_2"
#define CONNECT_MAIN_PHONE "jack_connect main:front-left system:playback_3 & jack_connect main:front-right system:playback_4"
#define DISCONNECT_MAIN_MASTER "jack_disconnect main:front-left system:playback_1 & jack_disconnect main:front-right system:playback_2"
#define DISCONNECT_MAIN_PHONE "jack_disconnect main:front-left system:playback_3 & jack_disconnect main:front-right system:playback_4"

const char *vol[3] = {
	"pactl set-sink-volume jack_out ",
	"pactl set-source-volume alsa_input.pci-0000_00_1b.0.analog-stereo.echo-cancel ", 
	"pactl set-sink-volume jack_out.2 "
};

const char *mast[4] = {
	"jack_disconnect main:front-left system:playback_1 & jack_disconnect main:front-right system:playback_2",
	"jack_disconnect music:front-left system:playback_1 & jack_disconnect music:front-right system:playback_2",
	"jack_connect main:front-left system:playback_1 & jack_connect main:front-right system:playback_2",
	"jack_connect music:front-left system:playback_1 & jack_connect music:front-right system:playback_2"
};

const char *phon[4] = {
	"jack_disconnect main:front-left system:playback_3 & jack_disconnect main:front-right system:playback_4",
   	"jack_disconnect music:front-left system:playback_3 & jack_disconnect music:front-right system:playback_4",
	"jack_connect main:front-left system:playback_3 & jack_connect main:front-right system:playback_4",
	"jack_connect music:front-left system:playback_3 & jack_connect music:front-right system:playback_4"
};

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
	 1 //36
 };

int ledStatus[37] = {0};

keyFunc buttons[37] = {
	&mainVolume, //0
	&noFunc, //1
	&musicVolume, //2 
	&noFunc, //3
	&noFunc, //4 
	&noFunc, //5
	&previousSong, //6 
	&nextSong, //7
	&noFunc, //8 
	&noFunc, //9
	&noFunc, //10
	&noFunc, //11
	&mainMaster, //12
	&mainPhone, //13
	&noFunc, //14
	&noFunc, //15 
	&noFunc, //16 
	&micVolume, //17
	&noFunc, //18
	&noFunc, //19
	&musicMaster, //20
	&musicPhone, //21 
	&noFunc, //22
	&noFunc, //23
	&noFunc, //24 
	&noFunc, //25 
	&pauseSpotify, //26
	&noFunc, //27
	&noFunc, //28
	&noFunc, //29
	&noFunc, //30
	&noFunc, //31
	&noFunc, //32
	&noFunc, //33
	&noFunc, //34
	&noFunc, //35
	&noFunc  //36
};
