#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"
#include "menu.h"
#include "gestion.h"
#include "scrol.h"


int main()
{

var act;//declaration
ennemi e;
backg b;
initialisation(&act);
loadimg(&act);
gestionn a;
scr s;
//

int now=0;
int ex=0;
int pfps=1;
int dt=0;
int vie=2,keys=1;
float pfpss=0;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
act.screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);

initbackground(&b);
initgestiondeviescore(&a);
initscrol(&s);

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

scrolling(&s , &act.game, &act.run,act.screen);
gestiondevieetscore(&a,vie,keys,act.screen);
affichebackground(s.level,act.time,act.screen,&s.camera,&b);
}else
 SDL_Delay(pfps-dt);
}


}

freesur(&act,&e);
freesurfaces(&b);
freesurfacesdegestion(&a);

SDL_Quit();
return 0;
}

