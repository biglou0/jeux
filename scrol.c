#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrol.h"
void scrolling(scr * s , int * game, int * run,SDL_Surface* screen,SDL_Surface* backg1,SDL_Surface* backg2,SDL_Surface* backg3){
//backg1=IMG_Load("ress/gamebackg.png");
switch(s->ev.type)
{
case SDL_QUIT:
{
*game=0;
*run=0;
  }
break;
case SDL_KEYDOWN:
 if(s->ev.key.keysym.sym==SDLK_RIGHT){
s->camera.x+=10;
s->persorect.x+=3;
}
 if(s->ev.key.keysym.sym==SDLK_LEFT){
if(s->camera.x!=0){
s->camera.x-=10;
s->persorect.x=s->camera.x+100;}}
}
 if(s->ev.key.keysym.sym==SDLK_DOWN){
s->persorect.y+=2;}
 if(s->ev.key.keysym.sym==SDLK_UP){
s->persorect.y-=2;}
if(s->camera.x>=6600){
s->level++;
SDL_Delay(200);
s->camera.x=0;
s->persorect.x=100;
}
if(s->level==1)
SDL_BlitSurface(s->perso,NULL,screen,&s->persorect);
if(s->level==2)
SDL_BlitSurface(s->perso,NULL,backg2,&s->persorect);
if(s->level==3)
SDL_BlitSurface(s->perso,NULL,backg3,&s->persorect);
//SDL_FreeSurface(backg1);
//SDL_FillRect(backg1, NULL, SDL_MapRGB(backg1->format, 101, 102, 103));
SDL_Flip(screen);
}

void initscrol(scr * s){
s->camera.x=0;
s->camera.y=0;
s->camera.w=1300;
s->camera.h=705;
s->level=1;
s->persorect.x=100;
s->persorect.y=300;
s->persorect.w=200;
s->persorect.h=200;
s->perso=IMG_Load("ress/keyon.png");
}





