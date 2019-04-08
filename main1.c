
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
//#include "COLLISION.h"

#include <SDL/SDL_ttf.h>
#include "objet.h"

int main()
{
SDL_Surface *ecran;
objet o;
int running=1;
while(running)
{
SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
init_objet(&o,ecran);
afficherobjet(&o,ecran);
//Collision(box1,00box2);
}
SDL_Quit();
return 0;
}




