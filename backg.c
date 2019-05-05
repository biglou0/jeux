#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
#include "backg.h"
#include <SDL/SDL_ttf.h>
void initbackground(backg *b ){
int t;
b->gamebackglvl1=IMG_Load("ress/gamebackg.png");
b->gamebackglvl2=IMG_Load("ress/gamebackglvl2.png");
b->gamebackglvl3=IMG_Load("ress/gamebackglvl3.png");
b->end1=IMG_Load("ress/1min.png");
b->end2=IMG_Load("ress/2min.png");
b->end3=IMG_Load("ress/3min.png");
b->end4=IMG_Load("ress/4min.png");
b->backgr.x=0;
b->backgr.y=0;
b->backgr.w=1300;
b->backgr.h=705;
//b->music = Mix_LoadMUS("music.mp3");
}

void affichebackground(int level ,int time ,SDL_Surface* screen, SDL_Rect * camera, backg *b){
int t;
//Mix_PlayMusic(b->music,-1);
switch(level)
{
case 1:
SDL_BlitSurface(b->gamebackglvl1,camera,screen,NULL);
break ;
case 2:
SDL_BlitSurface(b->gamebackglvl2,camera,screen,NULL);
break ;
case 3:
SDL_BlitSurface(b->gamebackglvl3,camera,screen,NULL);
break ;
} } 
void freesurfaces(backg *b){
SDL_FreeSurface(b->gamebackglvl1);
SDL_FreeSurface(b->gamebackglvl2);
SDL_FreeSurface(b->gamebackglvl3);
SDL_FreeSurface(b->end1);
SDL_FreeSurface(b->end2);
SDL_FreeSurface(b->end3);
SDL_FreeSurface(b->end4);
//Mix_FreeMusic(b->music);
}



