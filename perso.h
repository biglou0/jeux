#ifndef perso_H
#define perso_H
#include <SDL/SDL.h>
#include "background.h"

		

		
struct perso{
	SDL_Rect position;
	SDL_Surface * image[5];
	int score;
	int vie;
	
	int direction; //0:right 1:left 2:up
	int moving; //0:not moving 1:moving
	float Mass;

	double velocity;
	double acceleration;
};
typedef struct perso perso;

int loadpersoImages(perso * A);

void initperso(perso *A);

void moveperso(perso *A,Background *B,Uint32 dt);


void freeperso(perso *A);

#endif
