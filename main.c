#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "backg.h"
#include "menu.h"
#include "gestion.h"
#include "scrol.h"
#include "condition.h"
#include "save.h"

int main()
{

var act;//declaration
ennemi e;
backg b;
initialisation(&act);
loadimg(&act);
gestionn a;
scr s;
condition f;
//
saved sa;
int now=0;
int ex=0;
int pfps=1;
int dt=0;
int vie=2,keys=3;
int time;
float pfpss=0;
int off=1;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
act.screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);

initbackground(&b);
initgestiondeviescore(&a);
initscrol(&s);
 initcond(&f);
initsave(&sa);

load(&sa);
s.level=sa.level;
keys=sa.keys;
vie=sa.vie;
s.camera.x=sa.camx;
s.persorect.x=sa.persox;
s.persorect.y=sa.persoy;
while (act.game){
now=SDL_GetTicks();
act.time=SDL_GetTicks();
dt=now-ex;
while(act.menu)
{
if(dt>=pfps)
{

action(&act);
blit(&act);

ex=now;
}else
 SDL_Delay(pfps-dt);
}

while(act.settingg){
if(dt>=pfps)
{
fsettings(&act);

}else
 SDL_Delay(pfps-dt);
}



while(act.run){
if(dt>=pfps)
{
SDL_PollEvent(&s.ev);
cond(s.level , &f,vie,act.screen);
scrolling(&s , &act.game, &act.run,act.screen,b.gamebackglvl1,b.gamebackglvl2,b.gamebackglvl3);
time=gestiondevieetscore(&a,vie,keys,act.screen,sa.temp);
affichebackground(s.level,act.time,act.screen,&s.camera,&b);
save(s.level,vie,keys,s.ev,act.screen,&sa,time,s.persorect.x,s.persorect.y,s.camera.x);
}else
 SDL_Delay(pfps-dt);
}


}
SDL_Flip(act.screen);
freesur(&act,&e);
freesurfaces(&b);
freesurfacesdegestion(&a);

SDL_Quit();
return 0;
}

