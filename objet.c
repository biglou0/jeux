
#include "objet.h"


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void pause();

void init_objet(objet *o,SDL_Surface *ecran)

{

//SDL_Init(SDL_INIT_VIDEO);

   // ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
SDL_Rect positionecran;

positionecran.x = 0;
positionecran.y = 0;

o->position1.x = 100;
    o->position1.y = 70;
o->position2.x = 200;
    o->position2.y = 70;
 o->position3.x = 300;
   o->position3.y = 70;
o->position4.x = 400;
   o->position4.y = 70;
o->position5.x = 600;
   o->position5.y = 70;


	o->image1=SDL_LoadBMP("/home/amina/caisse_ok.bmp");
	o->image2=IMG_Load("/home/amina/caisse-ConvertImage.bmp");
	o->image3=IMG_Load("/home/amina/Downloads/mur.bmp");

		o->image4=IMG_Load("/home/amina/feushiha.png");

		o->image5=IMG_Load("/home/amina/mur.jpeg");



}

void afficherobjet(objet *o,SDL_Surface *ecran)
{
 
SDL_BlitSurface(o->image1,NULL,ecran,&o->position1);
SDL_BlitSurface(o->image2, NULL, ecran,&o->position2);
SDL_BlitSurface(o->image3, NULL, ecran,&o->position3);
SDL_BlitSurface(o->image4, NULL, ecran,&o->position4);
SDL_BlitSurface(o->image5, NULL, ecran,&o->position5);
     
// On blitte par-dessus l'écran
    SDL_Flip(ecran);
    pause();

    //SDL_FreeSurface(imageDeFond); /* On libère la surface */
   // SDL_Quit();


}

















