#define SCREEN_WIDTH 800   
#define SCREEN_HEIGHT 600

#define SPLASH_SCREEN "resources/longtimeago.png"

#ifndef DEMO
    #define DEMO 0
#endif

#ifndef SPLASH
    #define SPLASH 1
#endif

#ifndef FULLSCREEN
    #define FULLSCREEN 0
#endif

#define MAX_SND_CHANNELS 8

enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_FILA
};

enum{
    SND_SPLASH = 0,
    SND_PLAYER_COLLECT = 1,
    SND_FILA_REMOVE = 2,
    SND_PLAYER_FAIL = 3
};