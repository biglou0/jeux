#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "condition.h"

void initcond(condition * a) {
a->over.x=0;
a->over.y=0;
a->over.w=1300;
a->over.h=705;
a->ba=IMG_Load("ress/black.png");
a->pause=0;
}
void cond(int level , condition* c,int vie,SDL_Surface* screen){

char tt[150];
char op[150];
int minute = 0;
int seconde = 0;
int timeTemps = 0;
timeTemps = SDL_GetTicks();
minute = (timeTemps / 1000) / 60;
seconde = (timeTemps / 1000) % 60;
sprintf(tt, "You Cleared the Game in \n %dmin and %dsec", minute, seconde);
sprintf(op, "Game Over in \n %dmin and %dsec", minute, seconde);
if(level==4||vie==0){
c->pause++;
while(c->pause){
SDL_PollEvent(&c->event);
switch(c->event.type)
{case SDL_QUIT:
c->pause=0;
break;}
if(level==4){
	TTF_Init();
SDL_BlitSurface(c->ba,NULL,screen,&c->over);
c->font=TTF_OpenFont("o.ttf",80);
	SDL_Color couleurtexte = {250,0,0};
c->ch=TTF_RenderText_Solid(c->font,tt ,couleurtexte);
	SDL_BlitSurface(c->ch, NULL,screen,&c->over); 
SDL_Flip(screen);
SDL_FreeSurface(c->ch);
TTF_CloseFont(c->font);
	TTF_Quit();
}
if(vie==0){
	TTF_Init();
SDL_BlitSurface(c->ba,NULL,screen,&c->over);
c->font=TTF_OpenFont("o.ttf",80);
	SDL_Color couleurtexte = {250,0,0};
c->ch=TTF_RenderText_Solid(c->font,op ,couleurtexte);
	SDL_BlitSurface(c->ch, NULL,screen,&c->over); 
SDL_Flip(screen);
SDL_FreeSurface(c->ch);
TTF_CloseFont(c->font);
	TTF_Quit();}

}
}
	}
