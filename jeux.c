#include "jeux.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define WIDTH 9500
#define HEIGHT 3525
void init_perso(perso *p1) 
{
 (p1->positionperso.x)=750;
 (p1->positionperso.y)=200;
 (p1->val1)=0 ;
 (p1->val2)=3 ;
 
 
}
void loadimg(perso *p1)
{
	
        (p1->pers[0])=IMG_Load("perso00.png");
	(p1->pers[1])=IMG_Load("perso11.png");
	(p1->pers[2])=IMG_Load("perso00.png");
	(p1->pers[3])=IMG_Load("perso22.png");
	(p1->pers[4])=IMG_Load("perso33.png");
	(p1->pers[5])=IMG_Load("perso22.png");
        
}
void updateperso(perso *p1,int test)
{
fprintf(stderr,"fil update test %d\n",test);
 if(test==1)

 (p1->val2)++;
p1->positionperso.x += 20;



if(test==2)

 (p1->val1)++;
p1->positionperso.x -= 20;

if(test==3)

 (p1->val1)++;
p1->positionperso.y += 20;

if(test==4)

(p1->val1)++;
p1->positionperso.y -= 20;




if((p1->val1)>=2)
(p1->val1)=0;
if((p1->val2)>=5)
(p1->val2)=3;


}

void displayperso(perso p1,SDL_Surface *ecran,int test)
{
fprintf(stderr,"9bal test %d\n",test);
if(test==1)
{
SDL_BlitSurface(p1.pers[p1.val2],NULL,ecran,&(p1.positionperso));
fprintf(stderr,"%d\n",p1.val2);
}
else  if(test==2)
{
SDL_BlitSurface(p1.pers[p1.val1],NULL,ecran,&(p1.positionperso));
fprintf(stderr,"%d\n",p1.val1);
}
 
else if(test==3)
{
SDL_BlitSurface(p1.pers[p1.val1],NULL,ecran,&(p1.positionperso));
}
 
else 
{
SDL_BlitSurface(p1.pers[p1.val1],NULL,ecran,&(p1.positionperso));
}

}
void perso_freeperso1(perso *p1) 
{

SDL_FreeSurface(p1->pers[0]);
SDL_FreeSurface(p1->pers[1]);
SDL_FreeSurface(p1->pers[2]);

SDL_FreeSurface(p1->pers[3]);
SDL_FreeSurface(p1->pers[4]);
SDL_FreeSurface(p1->pers[5]);


}
SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y)
{
  SDL_Color color;
  Uint32 col = 0;
  //determine position
  char* pPosition = (char*) pSurface->pixels;
  //offset by y
  pPosition += (pSurface->pitch * y);
  //offset by x
  pPosition += (pSurface->format->BytesPerPixel * x);
  //copy pixel data
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  //convert color
  SDL_GetRGB (col, pSurface->format, &color.r , &color.g, &color.b);
  return (color);
}


int collision_p1(SDL_Surface *back,perso p1,scrol s)
{
	int verif=0;
	int i;
	SDL_Color couleur[1];

	couleur[0] =    GetPixel(back,s.positioncamera.x+250,s.positioncamera.y+400);

for(i=0;i<1;i++)
	{
		if((couleur[i].r == 238) && ((couleur[i].g == 238) && (couleur[i].b == 238))) 
		{
			verif=1;
			break;
		}


}
	return verif;
}
void init_camera(scrol *s)  
{
//s->bleu
//s1-orange
        s->positioncamera.x=1000;
        s->positioncamera.y=600;
        s->positioncamera.w=1000;
        s->positioncamera.h=600;
	
}


void set_camera_left(scrol *s,perso *p1,int test)
{
if(test==1)
{
if (s->positioncamera.x>(p1->positionperso.x-p1->positionperso.w*.5)-(WIDTH*.5))
{
s->positioncamera.x -=40;
s->positioncamera.y+=10;
}
else
{ 
s->positioncamera.x -=40; 
s->positioncamera.y+=10;
} 
}}



void set_camera_right(scrol *s,perso *p1,int test)
{
if (test==2)
{
if (s->positioncamera.x>(p1->positionperso.x-p1->positionperso.w*.5)-(WIDTH*.5))
{
s->positioncamera.x +=40;
s->positioncamera.y-=10;
}
else 
{
s->positioncamera.x +=40;
s->positioncamera.y-=10;

} 
}
}



void set_camera_up(scrol *s,perso *p1,int test)
{
if (test==3)
{
if (s->positioncamera.x>(p1->positionperso.y-p1->positionperso.h*.5)-(HEIGHT*.5))
{

s->positioncamera.x -=40;
s->positioncamera.y-=40;
}
else
{
s->positioncamera.x -=40;
s->positioncamera.y-=40;
} 
}
}


void set_camera_down(scrol *s,perso *p1,int test)
{
if (test==4)
{
if (s->positioncamera.x>(p1->positionperso.y-p1->positionperso.h*.5)-(HEIGHT*.5))
{
s->positioncamera.x +=40;
s->positioncamera.y+=40;
}
else
{
s->positioncamera.x +=40;
s->positioncamera.y+=40; 
}
}
}

