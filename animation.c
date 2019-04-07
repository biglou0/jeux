#include "animation.h"
#include "scrolling.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


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

