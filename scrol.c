#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrol.h"
void scrolling(scr * s , int * game, int * run,SDL_Surface* screen){
SDL_PollEvent(&s->ev);
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
s->camera.x+=10;}
 if(s->ev.key.keysym.sym==SDLK_LEFT){
if(s->camera.x!=0){
s->camera.x-=10;}}
}
if(s->camera.x>=6600){
s->level++;
SDL_Delay(200);
s->camera.x=0;
}
SDL_Flip(screen);
}

void initscrol(scr * s){
s->camera.x=0;
s->camera.y=0;
s->camera.w=1300;
s->camera.h=705;
s->level=1;
}





