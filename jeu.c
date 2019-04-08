#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jeu.h"
void inti(ennemi *e)
{
e->ennemirect.x=200;
e->ennemirect.y=500;
e->ennemii=IMG_Load("ress/t.png");
}

void affiche(ennemi *e,SDL_Surface *screen)
{



SDL_GetClipRect(e->ennemii,&e->ennemirect);
SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);

}


int deplacement(ennemi *e)
{  int direction=0;
   int min=100;
  int max=200;


  
   if(direction==0)

   {
    while(e->ennemirect.x>min)
     
       {
       e->ennemirect.x--;
       direction=1;
      return direction;
       }  
   }
  else
     if(direction==1)
 
   {
    while(e->ennemirect.x<max)
      {
      e->ennemirect.x++;
      return direction;
      }
  }

}


void animation(ennemi *e, int direction,SDL_Surface *screen)
{  

  
  
   if(direction==0)

   {
    
    //img:1;
    e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  


      //img:1;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  


        //img:3;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  

   //img:4;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  
     
 
   }
else
  if(direction==1)
 
   {
   
    //img:1;
    e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  


      //img:1;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  


        //img:3;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect);  

   //img:4;
     e->ennemii=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemii,&e->ennemirect);
    SDL_BlitSurface(e->ennemii,NULL,screen,&e->ennemirect); 
   }

}
