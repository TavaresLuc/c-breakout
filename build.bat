gcc src/main.c src/spawn.c src/sound.c src/splashScreen.c src/input.c src/init.c src/draw.c src/hero.c -DSPLASH=0 -DFULLSCREEN=0 SDL2.dll SDL2_mixer.dll SDL2_image.dll -o dist/heroes
xcopy /s resources dist\resources
dist/heroes.exe