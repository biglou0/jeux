#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "menu.h"




int main()
{

var act;//struct de var
initialisation(&act);
freesur(&act);
loadimg(&act);
int now=0;
int ex=0;
int pfps=1;
int dt=0;
float pfpss=0;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
act.screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
while (act.game){
now=SDL_GetTicks();
dt=now-ex;
while(act.menu)
{
if(dt>=pfps)
{
//update
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
backgroundandscrolling(&act);

}else
 SDL_Delay(pfps-dt);
}


}

freesur(&act);
SDL_Quit();
return 0;
}

