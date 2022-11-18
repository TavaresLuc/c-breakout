#define SCREEN_WIDTH 1024   
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

#define BLOCKS_AMOUNT_1 28
#define BLOCKS_AMOUNT_2 20
#define BLOCKS_AMOUNT_3 28
#define BLOCKS_AMOUNT_4 20
#define WALLS_AMOUNT 20

enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_FILA
};

enum{
    SND_SPLASH = 0,
    SND_WALL_BOUNCE = 1,
    SND_BLOCK_BOUNCE = 2,
    SND_PLATFORM_BOUNCE = 3,
    SND_BORDER_BOUNCE = 4
};
