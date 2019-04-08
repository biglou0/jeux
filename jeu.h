#ifndef JEU_H
#define JEU_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
SDL_Surface* ennemii;
SDL_Rect ennemirect;
SDL_Surface* screen;

}ennemi;
void inti(ennemi *e);
void affiche(ennemi *e,SDL_Surface *screen);
int deplacement(ennemi *e);
void animation(ennemi *e, int direction,SDL_Surface *screen);

#endif
