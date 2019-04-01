#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "menu.h"

void loadimg(var * act){
act->gamebackglvl1=IMG_Load("ress/gamebackg.png");
act->gamebackglvl2=IMG_Load("ress/gamebackglvl2.png");
act->gamebackglvl3=IMG_Load("ress/gamebackglvl3.png");
act->backg=SDL_LoadBMP("ress/def.bmp");
act->play=IMG_Load("ress/aa.png");
act->setting=IMG_Load("ress/set.png");
act->leave=IMG_Load("ress/leave.png");
act->Hplay=IMG_Load("ress/aasel.png");
act->Hset=IMG_Load("ress/setsel.png");
act->Hleave=IMG_Load("ress/leavesel.png");
SDL_GetClipRect(act->backg,& act->backgrect);
SDL_WM_SetCaption("Fairy Tail",NULL);}



void blit(var * act ){
SDL_BlitSurface(act->backg,NULL,act->screen,& act->backgrect);
if(act->etat==3){
SDL_BlitSurface(act->Hplay,NULL,act->screen,&act->playrect);
SDL_BlitSurface(act->setting,NULL,act->screen,&act->settingrect);
SDL_BlitSurface(act->leave,NULL,act->screen,&act->leaverect);}
if(act->etat==2){
SDL_BlitSurface(act->play,NULL,act->screen,&act->playrect);
SDL_BlitSurface(act->Hset,NULL,act->screen,&act->settingrect);
SDL_BlitSurface(act->leave,NULL,act->screen,&act->leaverect);}
if(act->etat==1){
SDL_BlitSurface(act->Hleave,NULL,act->screen,&act->leaverect);
SDL_BlitSurface(act->play,NULL,act->screen,&act->playrect);
SDL_BlitSurface(act->setting,NULL,act->screen,&act->settingrect);}
if(act->etat==4){
SDL_BlitSurface(act->leave,NULL,act->screen,&act->leaverect);
SDL_BlitSurface(act->play,NULL,act->screen,&act->playrect);
SDL_BlitSurface(act->setting,NULL,act->screen,&act->settingrect);}
 if(act->etat==0)
act->etat=4;

if(act->etat==5)
act->etat=1;
SDL_Flip(act->screen);
}






void freesur(var * act ){
SDL_FreeSurface(act->play);
SDL_FreeSurface(act->setting);
SDL_FreeSurface(act->leave);
SDL_FreeSurface(act->Hplay);
SDL_FreeSurface(act->Hset);
SDL_FreeSurface(act->Hleave);
SDL_FreeSurface(act->backg);
SDL_FreeSurface(act->menuu);
SDL_FreeSurface(act->backb);
SDL_FreeSurface(act->flowb);
SDL_FreeSurface(act->on);
SDL_FreeSurface(act->off);

}




void action(var * act ){
SDL_PollEvent(&act->event);
switch(act->event.type)
{case SDL_QUIT:
{
act->menu=0;
 act->game=0;
  }
break;
case SDL_KEYDOWN:
 if(act->event.key.keysym.sym==SDLK_DOWN)

  {

act->etat--;
SDL_Delay(100);
  }
 if(act->event.key.keysym.sym==SDLK_UP)

  {
act->etat++;
SDL_Delay(100);
  }

 if(act->event.key.keysym.sym==SDLK_RETURN)

  {	if(act->etat==1){act->menu=0;}
if(act->etat==2){act->settingg=1;act->menu=0;}
if(act->etat==3){act->run=1,act->menu=0;}


}
break;
case SDL_MOUSEMOTION:

if(94<act->event.motion.x&&act->event.motion.x<284)
{if(448<act->event.motion.y&&act->event.motion.y<506)
{
//update
act->etat=3;
}
else if(518<act->event.motion.y&&act->event.motion.y<574)
{
//update
act->etat=2;
}
else if(596<act->event.motion.y&&act->event.motion.y<652)
{
//update
act->etat=1;
}


}

break;
case SDL_MOUSEBUTTONDOWN:
if( act->event.button.button == SDL_BUTTON_LEFT )
		{

if(94<act->event.button.x&&act->event.button.x<284)
{if(596<act->event.button.y&&act->event.button.y<652)
{
act->menu=0;
 act->game=0;
}else if(448<act->event.button.y&&act->event.button.y<506)
{
act->menu=0;
act->run=1;}else if(518<act->event.button.y&&act->event.button.y<574)
{
act->menu=0;
act->settingg=1;}
}
}
break;
}}







void initialisation(var *act ){
act->level=1;
act->keys=0;
act->vie=3;
act->camera.x=0;
act->camera.y=0;
act->camera.w=1300;
act->camera.h=705;
act->screen=NULL;
act->screenrect.x=0;
act->screenrect.y=0;
act->screenrect.w=0;
act->screenrect.h=0;
act->backg=NULL;
act->backgrect.x=0;
act->backgrect.y=0;
act->backgrect.w=0;
act->backgrect.h=0;
act->play=NULL;
act->playrect.x=74;
act->playrect.y=450;
act->playrect.w=230;
act->playrect.h=58;
act->setting=NULL;
act->settingrect.x=74;
act->settingrect.y=530;
act->settingrect.w=230;
act->settingrect.h=58;
act->leave=NULL;
act->leaverect.x=74;
act->leaverect.y=610;
act->leaverect.w=230;
act->leaverect.h=58;
act->Hplay=NULL;
act->Hset=NULL;
act->Hleave=NULL;
act->tmp=NULL;
act->flowb=NULL;
act->menuu=NULL;
act->menub.x=200;
act->menub.y=100;
act->menub.w=800;
act->menub.h=600;
act->backb=NULL;
act->backr.x=650;
act->backr.y=500;
act->backr.w=230;
act->backr.h=58;
act->on=NULL;
act->off=NULL;
act->setm.x=750;
act->setm.y=218;
act->setm.w=100;
act->setm.h=50;
act->sets.x=750;
act->sets.y=340;
act->sets.w=100;
act->sets.h=50;
act->setshadow.x=750;
act->setshadow.y=448;
act->setshadow.w=100;
act->setshadow.h=50;
act->son=1;
act->music=1;
act->shadow=1;
act->run=0;
act->menu=1;
act->etat=4;
act->game=1;
act->settingg=0;
}






void fsettings(var * act){
act->menuu=IMG_Load("ress/menu.png");
act->backb=IMG_Load("ress/back.png");
act->flowb=SDL_LoadBMP("ress/flouu.bmp");
act->on=IMG_Load("ress/on.png");
act->off=IMG_Load("ress/off.png");
SDL_BlitSurface(act->flowb,NULL,act->screen,&act->backgrect);
SDL_BlitSurface(act->menuu,NULL,act->screen,&act->menub);
if(act->music==1){
SDL_BlitSurface(act->on,NULL,act->screen,&act->setm);}
if(act->music==0){
SDL_BlitSurface(act->off,NULL,act->screen,&act->setm);}
if(act->son==1){
SDL_BlitSurface(act->on,NULL,act->screen,&act->sets);}
if(act->son==0){
SDL_BlitSurface(act->off,NULL,act->screen,&act->sets);}
if(act->shadow==1){
SDL_BlitSurface(act->on,NULL,act->screen,&act->setshadow);}
if(act->shadow==0){
SDL_BlitSurface(act->off,NULL,act->screen,&act->setshadow);}
SDL_Flip(act->screen);
SDL_PollEvent(&act->event);
switch(act->event.type)
{case SDL_QUIT:
act->settingg=0;
act->menu=1;
break;
case SDL_KEYDOWN:
 if(act->event.key.keysym.sym==SDLK_ESCAPE){
act->settingg=0;
act->menu=1;
SDL_Delay(200);}
break;
case SDL_MOUSEBUTTONDOWN:
if( act->event.button.button == SDL_BUTTON_LEFT )
		{

if(750<act->event.button.x&&act->event.button.x<850)
{if(218<act->event.button.y&&act->event.button.y<258)
{
act->music++;
SDL_Delay(200);
if(act->music==2){act->music=0;}
}else if(340<act->event.button.y&&act->event.button.y<383)
{
act->son++;
SDL_Delay(200);
if(act->son==2){act->son=0;}
}else if(448<act->event.button.y&&act->event.button.y<488)
{
act->shadow++;
SDL_Delay(200);
if(act->shadow==2){act->shadow=0;}
}
}
}
break;
}}




void backgroundandscrolling(var * act){
int time;
act->levelup=IMG_Load("ress/clear.png");
SDL_PollEvent(&act->event);
switch(act->event.type)
{
case SDL_QUIT:
{
act->game=0;
 act->run=0;
  }
break;
case SDL_KEYDOWN:
 if(act->event.key.keysym.sym==SDLK_RIGHT){
act->camera.x+=10;}
 if(act->event.key.keysym.sym==SDLK_LEFT){
if(act->camera.x!=0){
act->camera.x-=10;}}
}
if(act->camera.x>=6600){
act->level++;
SDL_Delay(200);
act->camera.x=0;
}
switch(act->level)
{
case 1:
SDL_BlitSurface(act->gamebackglvl1,&act->camera,act->screen,NULL);
break ;
case 2:
SDL_BlitSurface(act->gamebackglvl2,&act->camera,act->screen,NULL);
break ;
case 3:
SDL_BlitSurface(act->gamebackglvl3,&act->camera,act->screen,NULL);
break ;
case 4:
time=act->time/1000;
if(time<60)
{
act->end=IMG_Load("ress/1min.png");
SDL_BlitSurface(act->end,NULL,act->screen,&act->backgrect);}
else if(time<120)
{
act->end=IMG_Load("ress/2min.png");
SDL_BlitSurface(act->end,NULL,act->screen,&act->backgrect);}
else if(time<180)
{
act->end=IMG_Load("ress/3min.png");
SDL_BlitSurface(act->end,NULL,act->screen,&act->backgrect);}
else 
{
act->end=IMG_Load("ress/4min.png");
SDL_BlitSurface(act->end,NULL,act->screen,&act->backgrect);}
break;
} 
SDL_Flip(act->screen);
}

void gestiondevieetscore(var * act){
act->heart=IMG_Load("ress/heart.png");
act->key=IMG_Load("ress/key.png");
act->keyon=IMG_Load("ress/keyon.png");
act->level1.x=1150;
act->level1.y=30;
act->level1.w=50;
act->level1.h=50;
act->level2.x=1200;
act->level2.y=30;
act->level2.w=50;
act->level2.h=50;
act->level3.x=1250;
act->level3.y=30;
act->level3.w=50;
act->level3.h=50;
act->key1.x=1150;
act->key1.y=80;
act->key1.w=50;
act->key1.h=50;
act->key2.x=1200;
act->key2.y=80;
act->key2.w=50;
act->key2.h=50;
act->key3.x=1250;
act->key3.y=80;
act->key3.w=50;
act->key3.h=50;
switch(act->vie){

case 1:
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level1);
break;
case 2:
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level1);
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level2);
break;
case 3:
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level1);
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level2);
SDL_BlitSurface(act->heart,NULL,act->screen,&act->level3);
break;

}
switch(act->keys){
case 3:
SDL_BlitSurface(act->key,NULL,act->screen,&act->key1);
SDL_BlitSurface(act->key,NULL,act->screen,&act->key2);
SDL_BlitSurface(act->key,NULL,act->screen,&act->key3);
break;
case 2:
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key1);
SDL_BlitSurface(act->key,NULL,act->screen,&act->key2);
SDL_BlitSurface(act->key,NULL,act->screen,&act->key3);
break;
case 1:
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key1);
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key2);
SDL_BlitSurface(act->key,NULL,act->screen,&act->key3);
break;
case 0:
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key1);
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key2);
SDL_BlitSurface(act->keyon,NULL,act->screen,&act->key3);
break;

}
SDL_Flip(act->screen);
}

