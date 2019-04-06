#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "gestion.h"

void initgestiondeviescore(gestionn * a) {
a->heart=IMG_Load("ress/heart.png");
a->key=IMG_Load("ress/key.png");
a->keyon=IMG_Load("ress/keyon.png");
a->level1.x=1150;
a->level1.y=30;
a->level1.w=50;
a->level1.h=50;
a->level2.x=1200;
a->level2.y=30;
a->level2.w=50;
a->level2.h=50;
a->level3.x=1250;
a->level3.y=30;
a->level3.w=50;
a->level3.h=50;
a->key1.x=1150;
a->key1.y=80;
a->key1.w=50;
a->key1.h=50;
a->key2.x=1200;
a->key2.y=80;
a->key2.w=50;
a->key2.h=50;
a->key3.x=1250;
a->key3.y=80;
a->key3.w=50;
a->key3.h=50;
}






void gestiondevieetscore(gestionn * a , int vie , int keys ,SDL_Surface* screen){
switch(vie){

case 1:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
break;
case 2:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
SDL_BlitSurface(a->heart,NULL,screen,&a->level2);
break;
case 3:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
SDL_BlitSurface(a->heart,NULL,screen,&a->level2);
SDL_BlitSurface(a->heart,NULL,screen,&a->level3);
break;

}
switch(keys){
case 3:
SDL_BlitSurface(a->key,NULL,screen,&a->key1);
SDL_BlitSurface(a->key,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 2:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->key,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 1:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 0:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key2);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key3);
break;

}
SDL_Flip(screen);
}
void freesurfacesdegestion(gestionn *a){
SDL_FreeSurface(a->heart);
SDL_FreeSurface(a->key);
SDL_FreeSurface(a->keyon);
}


