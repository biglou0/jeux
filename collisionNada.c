#include <stdlib.h>
#include <stdio.h>
#include "collisionNada.h"
#include <SDL/SDL.h>



Uint32 GetPixel(SDL_Surface *pSurface, int x, int y)
{
        int bpp = pSurface->format->BytesPerPixel;

        /* p est l'adresse du pixel qu'on veut detecter*/

        Uint8 *p = (Uint8 *)pSurface->pixels + y * pSurface->pitch + x * bpp;
     
        switch(bpp) 
                    {
        case 1:
      return *p;
      break;
     
        case 2:
      return *(Uint16 *)p;
      break;
     
        case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
          return p[0] << 16 | p[1] << 8 | p[2];
      else
          return p[0] | p[1] << 8 | p[2] << 16;
      break;
     
        case 4:
      return *(Uint32 *)p;
      break;
     
        default:
      return 0;     
        }
}



/**/

   int collision_test (SDL_Surface *mask,int x,int y,int height)
   {
      int i;
      Uint8 r,g,b;
      for(i=y;i<=y+height-10;i++)
      {
        SDL_GetRGB(GetPixel(mask,x,i),mask->format,&r,&g,&b);
        if(r==0 && g==0 && b==0) break;
      }

      if(i<=y+height-10) return 0;
      else return 1;
   }

/**/

   int pixel_test(SDL_Surface *surface,int x,int y)
   {
      Uint8 r,g,b;
      SDL_GetRGB(GetPixel(surface,x,y),surface->format,&r,&g,&b);
      if(r==0 && g==0 && b==0)
      {
        return 0;
      }
      else 
      {
        return 1;
      }
   }



/**/

/*int Collision(SDL_Rect a, SDL_Rect b,SDL_Rect camera,int direction)
{
	
   if((b.x-(a.x+camera.x + 105)<=20) && direction==1)
          return 0; 
   else if((a.x+camera.x-b.x>=20) && direction==0)
          return 0;
        else return 1;
       
}*/


int Collision_Trigo(int x,int y,Cercle C)
{

   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>C.r*C.r)
      return 0;
   else
      return 1;
}

