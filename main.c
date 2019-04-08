#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeu.h"
#define LARGEUR 600
#define HAUTEUR 400
int main()
{
ennemi e;
e.ennemirect.y=500;
e.ennemirect.x=200;
int direction=0;
SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
int d=1;
SDL_Rect backgrect={0,0,0,0};
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
backg=SDL_LoadBMP("ress/55864962_439637820115794_871173514005053440_n.bmp");
SDL_GetClipRect(backg,&backgrect);
screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("jeu",NULL);
inti(&e);

while(d==1)
{
SDL_BlitSurface(backg,NULL,screen,&backgrect);


e.ennemirect.x=e.ennemirect.x+50;
affiche(&e,screen);
deplacement(&e);
animation(&e,direction,screen);


SDL_Flip(screen);
}
return 0;
}
