#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

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
a->timing.x=20;
a->timing.y=40;
a->timing.w=50;
a->timing.h=50;
}






int gestiondevieetscore(gestionn * a , int vie , int keys ,SDL_Surface* screen,int ex){
char tt[64]="25";
int t;
int minute = 0;
int seconde = 0;
int timeTemps;
if(ex!=0){
timeTemps = SDL_GetTicks();
minute = ((timeTemps+ex) / 1000) / 60;
seconde = ((timeTemps+ex) / 1000) % 60;}
if(ex==0){timeTemps = SDL_GetTicks();
minute = (timeTemps / 1000) / 60;
seconde = (timeTemps / 1000) % 60;}

sprintf(tt, "TEMPS : %d:%d", minute, seconde);
	TTF_Init();
a->fonttexte=TTF_OpenFont("o.ttf",30);
	SDL_Color couleurtexte = {0,0,0};
a->chrono=TTF_RenderText_Solid(a->fonttexte,tt,couleurtexte);
	SDL_BlitSurface(a->chrono, NULL,screen,&a->timing); 
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
SDL_FreeSurface(a->chrono);
TTF_CloseFont(a->fonttexte);
	TTF_Quit();
return timeTemps;
}
void freesurfacesdegestion(gestionn *a){
SDL_FreeSurface(a->heart);
SDL_FreeSurface(a->key);
SDL_FreeSurface(a->keyon);
}


