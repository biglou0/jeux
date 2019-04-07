
#include "objet.h"


void init_objet(objet *o,SDL_Surface *ecran)

{

SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
/*
positionecran.x = 0;
positionecran.y = 0;*/

	  o->position1.x = 5;
    o->position1.y = 5;
 //o->position2.x = 7;
  //  o->position2.y = 7;
// o->position3.x = 6;
   // o->position3.y = 6;
//o->position4.x = 700;
    //o->position4.y = 380;


	o->image1=IMG_Load("caisse.png");
	/*o->image2=IMG_Load("explo11.png");
	o->image3=IMG_Load("explo11.png");
	o->image4=IMG_Load("explo11.png");*/





}

void afficherobjet(objet *o,SDL_Surface *ecran)
{
 
SDL_BlitSurface(o->image1, NULL, ecran,&o->position1);
/*SDL_BlitSurface(o->image2, NULL, ecran,&o->position2);
SDL_BlitSurface(o->image3, NULL, ecran,&o->position3);
SDL_BlitSurface(o->image4, NULL, ecran,&o->position4);*/
 
SDL_Flip(ecran);
}

















