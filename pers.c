#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main(void){
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *personnage;
SDL_Rect positionecran;
SDL_Rect positionpersonnage;
SDL_Event event;

char pause;

if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1000,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return 1;
}


personnage = IMG_Load("loj.bmp");
positionecran.x = 0;
positionecran.y = 0;
positionpersonnage.x = 5;
positionpersonnage.y = 5;
if (personnage==NULL){
printf("Unable to load png: %s\n",SDL_GetError());
return 1;
}

int done =1 ;
int sourisDown;
while(done)
{


SDL_BlitSurface(image,NULL,screen,&positionecran);

SDL_BlitSurface(personnage,NULL,screen,&positionpersonnage);

while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
done= 0;
break;

case SDL_KEYDOWN:
 {
switch (event.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   done =0;
   break;
   case SDLK_s:
     positionpersonnage.y=positionpersonnage.y+10;
     break;
   case SDLK_z:
   positionpersonnage.y=positionpersonnage.y-10;
     break;
   case SDLK_d:
   positionpersonnage.x=positionpersonnage.x+10;
  break;
   case SDLK_q:
   positionpersonnage.x=positionpersonnage.x-10;
    break;}
case SDL_MOUSEBUTTONDOWN:
                sourisDown = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                sourisDown = 0;
                break;
            default : break;
 }
  if (sourisDown)
        {
            positionpersonnage.x = event.motion.x;
            positionpersonnage.y = event.motion.y;
        }




}
}



SDL_Flip(screen);

}

SDL_FreeSurface(image);
SDL_FreeSurface(personnage);
SDL_Quit();

return EXIT_SUCCESS;
pause= getchar();
return 0;
}
