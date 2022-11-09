#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#endif

extern void prepareScene(void);
extern void presentScene(void);
extern void resetScene(void);
extern SDL_Texture *loadTexture(char *file);
void blit(SDL_Texture *texture, int size, int x, int y, int center, int centerX);
void blitAtlas(SDL_Texture *texture, int sprX, int sprY, int xx, int yy, int size, int x, int y, int center);