#ifndef OBJET_H_INCLUDED

#define OBJET_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct {

SDL_Surface* image1;
SDL_Surface* image2;
SDL_Surface* image3;
SDL_Surface* image4;
SDL_Rect position1,position2,position3,position4;

}objet;
void init_objet(objet *o,SDL_Surface *ecran);

void afficherobjet(objet *o,SDL_Surface *ecran);


#endif


