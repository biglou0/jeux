
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include <time.h>

void inti(Ennemi *e)
{
e->ennemirect.x=900;
e->ennemirect.y=1300;
e->ennemi=IMG_Load("ress/t.png");
}

void affiche(Ennemi *e,SDL_Surface *screen)
{



SDL_GetClipRect(e->ennemi,&e->ennemirect);
SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);

}


int deplacement(Ennemi *e)
{  int direction=0;
   int min=700;
  int max=900;


  
   if(direction==0)

   {
    while(e->ennemirect.x<min)
     
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


void animation(Ennemi *e, int direction,SDL_Surface *screen)
{  

  
  
   if(direction==0)

   {
    
    //img:1;
    e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  


      //img:1;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  


        //img:3;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  

   //img:4;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  
     
 
   }
else
  if(direction==1)
 
   {
   
    //img:1;
    e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  


      //img:1;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  


        //img:3;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect);  

   //img:4;
     e->ennemi=IMG_Load("ress/t.png");
    SDL_GetClipRect(e->ennemi,&e->ennemirect);
    SDL_BlitSurface(e->ennemi,NULL,screen,&e->ennemirect); 
   }

}
/////aziz//






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
///amina//
void init_objet(objet *o,SDL_Surface *ecran)

{

SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
/*
positionecran.x = 0;
positionecran.y = 0;*/

	  o->position1.x = 5;
    o->position1.y = 5;
 //o->position2.x = 7;
  //  o->position2.y = 7;
// o->position3.x = 6;
   // o->position3.y = 6;
//o->position4.x = 700;
    //o->position4.y = 380;


	o->image1=IMG_Load("caisse.png");
	/*o->image2=IMG_Load("explo11.png");
	o->image3=IMG_Load("explo11.png");
	o->image4=IMG_Load("explo11.png");*/





}

void afficherobjet(objet *o,SDL_Surface *ecran)
{
 
SDL_BlitSurface(o->image1, NULL, ecran,&o->position1);
/*SDL_BlitSurface(o->image2, NULL, ecran,&o->position2);
SDL_BlitSurface(o->image3, NULL, ecran,&o->position3);
SDL_BlitSurface(o->image4, NULL, ecran,&o->position4);*/
 
SDL_Flip(ecran);
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
act->keys=2;
act->vie=1;
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








/////louj//
void init_perso(personnage *p1) 
{
 (p1->positionperso.x)=750;
 (p1->positionperso.y)=200;
 (p1->val1)=0 ;
 (p1->val2)=3 ;
 
 
}
void load(personnage *p1)
{
	
        (p1->pers[0])=IMG_Load("perso00.png");
	(p1->pers[1])=IMG_Load("perso11.png");
	(p1->pers[2])=IMG_Load("perso00.png");
	(p1->pers[3])=IMG_Load("perso22.png");
	(p1->pers[4])=IMG_Load("perso33.png");
	(p1->pers[5])=IMG_Load("perso22.png");
        
}
void updateperso(personnage *p1,int test)
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

void displayperso(personnage p1,SDL_Surface *ecran,int test)
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
void perso_freeperso1(personnage *p1) 
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


int collision_p1(SDL_Surface *back,personnage p1,scrol s)
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


void set_camera_left(scrol *s,personnage *p1,int test)
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



void set_camera_right(scrol *s,personnage *p1,int test)
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



void set_camera_up(scrol *s,personnage *p1,int test)
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


void set_camera_down(scrol *s,personnage *p1,int test)
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
///iheb///
void initgestiondeviescore(gestionn * a) {
a->heart=IMG_Load("ress/heart.png");
a->key=IMG_Load("ress/key.png");
a->keyon=IMG_Load("ress/keyon.png");
a->level1.x=1150;
a->level1.y=30;
a->level1.w=50;
a->level1.h=50;
a->level2.x=1200;
a->level2.y=30;
a->level2.w=50;
a->level2.h=50;
a->level3.x=1250;
a->level3.y=30;
a->level3.w=50;
a->level3.h=50;
a->key1.x=1150;
a->key1.y=80;
a->key1.w=50;
a->key1.h=50;
a->key2.x=1200;
a->key2.y=80;
a->key2.w=50;
a->key2.h=50;
a->key3.x=1250;
a->key3.y=80;
a->key3.w=50;
a->key3.h=50;
}






void gestiondevieetscore(gestionn * a , int vie , int keys ,SDL_Surface* screen){
switch(vie){

case 1:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
break;
case 2:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
SDL_BlitSurface(a->heart,NULL,screen,&a->level2);
break;
case 3:
SDL_BlitSurface(a->heart,NULL,screen,&a->level1);
SDL_BlitSurface(a->heart,NULL,screen,&a->level2);
SDL_BlitSurface(a->heart,NULL,screen,&a->level3);
break;

}
switch(keys){
case 3:
SDL_BlitSurface(a->key,NULL,screen,&a->key1);
SDL_BlitSurface(a->key,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 2:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->key,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 1:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key2);
SDL_BlitSurface(a->key,NULL,screen,&a->key3);
break;
case 0:
SDL_BlitSurface(a->keyon,NULL,screen,&a->key1);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key2);
SDL_BlitSurface(a->keyon,NULL,screen,&a->key3);
break;

}
SDL_Flip(screen);
}
void freesurfacesdegestion(gestionn *a){
SDL_FreeSurface(a->heart);
SDL_FreeSurface(a->key);
SDL_FreeSurface(a->keyon);
}

/////jihen//
void affichage(enigme *E ,int val)
{
int reponse=-1;
srand ( time(NULL) );
int random =1;
random= rand() %3+1;
	SDL_Surface *yes;
	SDL_Surface *no;
	SDL_Init(SDL_INIT_VIDEO);	
	TTF_Init();
	TTF_Font *fonttexte;
	fonttexte=TTF_OpenFont("o.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
	SDL_Surface *screen;
	SDL_Surface *question;
	SDL_Surface *re3;
	SDL_Surface *re4;
	SDL_Rect posquestion;
	SDL_Rect posrep3;
	SDL_Rect posrep4;
	SDL_Rect rzlt;
	screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
yes=IMG_Load("a.jpg");
no=IMG_Load("b.jpg");
	posquestion.x=255;
	posquestion.y=100;
	posrep3.x=100;
	posrep3.y=250;
	posrep3.h=100;
	posrep3.w=100;
	posrep4.x=355;
	posrep4.y=250;
	posrep4.h=100;
	posrep4.w=100;
	rzlt.x=0;
	rzlt.y=0;
	rzlt.h=705;
	rzlt.w=1300;
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));


 re3=TTF_RenderText_Shaded(fonttexte,"Yes",couleurtexte,couleur);
 re4=TTF_RenderText_Shaded(fonttexte,"No",couleurtexte,couleur);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

				/* Blit du texte */

	SDL_BlitSurface(re3, NULL,screen,&posrep3);
	SDL_BlitSurface(re4, NULL,screen,&posrep4);



int continuer = 1;
SDL_Event event;
while (continuer)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break ; 
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
{
if(100<event.button.x&&event.button.x<200)
{if(250<event.button.y&&event.button.y<350)
{
reponse=1;
}
}
if(355<event.button.x&&event.button.x<455)
{if(250<event.button.y&&event.button.y<350)
{
reponse=0;
}
}
}
break;}
if(random==1){
question=TTF_RenderText_Shaded(fonttexte,"14/2=6?",couleurtexte,couleur);}
else if(random==2){
question=TTF_RenderText_Shaded(fonttexte,"14/2=7?",couleurtexte,couleur);}
else if(random==3){
question=TTF_RenderText_Shaded(fonttexte,"244/2=122?",couleurtexte,couleur);}
	SDL_BlitSurface(question, NULL,screen,&posquestion); 
if(random==1){

if(reponse==0){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
}
if(random==2){

if(reponse==0){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
}
if(random==3){

if(reponse==0){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
}
SDL_Flip(screen);
}

TTF_CloseFont(fonttexte);
	TTF_Quit();
SDL_FreeSurface(question);
SDL_FreeSurface(re3);
SDL_FreeSurface(re4);
SDL_Quit();

}
////iheb//
void initbackground(backg *b ){
int t;
b->gamebackglvl1=IMG_Load("ress/gamebackg.png");
b->gamebackglvl2=IMG_Load("ress/gamebackglvl2.png");
b->gamebackglvl3=IMG_Load("ress/gamebackglvl3.png");
b->end1=IMG_Load("ress/1min.png");
b->end2=IMG_Load("ress/2min.png");
b->end3=IMG_Load("ress/3min.png");
b->end4=IMG_Load("ress/4min.png");
b->backgr.x=0;
b->backgr.y=0;
b->backgr.w=1300;
b->backgr.h=705;
}

void affichebackground(int level ,int time ,SDL_Surface* screen, SDL_Rect * camera, backg *b){
int t;
switch(level)
{
case 1:
SDL_BlitSurface(b->gamebackglvl1,camera,screen,NULL);
break ;
case 2:
SDL_BlitSurface(b->gamebackglvl2,camera,screen,NULL);
break ;
case 3:
SDL_BlitSurface(b->gamebackglvl3,camera,screen,NULL);
break ;
case 4:
t=time/1000;
if(t<60)
{
SDL_BlitSurface(b->end1,NULL,screen,&b->backgr);
}
else if(t<120)
{
SDL_BlitSurface(b->end2,NULL,screen,&b->backgr);
}
else if(t<180)
{
SDL_BlitSurface(b->end3,NULL,screen,&b->backgr);
}
else 
{
SDL_BlitSurface(b->end4,NULL,screen,&b->backgr);
}
break;
} } 
void freesurfaces(backg *b){
SDL_FreeSurface(b->gamebackglvl1);
SDL_FreeSurface(b->gamebackglvl2);
SDL_FreeSurface(b->gamebackglvl3);
SDL_FreeSurface(b->end1);
SDL_FreeSurface(b->end2);
SDL_FreeSurface(b->end3);
SDL_FreeSurface(b->end4);}


///iheb//
void loadimg(var * act){
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






void freesur(var * act , Ennemi *es){
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
SDL_FreeSurface(es->ennemi);
SDL_FreeSurface(act->tmp);
SDL_FreeSurface(act->levelup);

}




















///iheb//
void scrolling(scr * s , int * game, int * run,SDL_Surface* screen){
SDL_PollEvent(&s->ev);
switch(s->ev.type)
{
case SDL_QUIT:
{
*game=0;
*run=0;
  }
break;
case SDL_KEYDOWN:
 if(s->ev.key.keysym.sym==SDLK_RIGHT){
s->camera.x+=10;}
 if(s->ev.key.keysym.sym==SDLK_LEFT){
if(s->camera.x!=0){
s->camera.x-=10;}}
}
if(s->camera.x>=6600){
s->level++;
SDL_Delay(200);
s->camera.x=0;
}
SDL_Flip(screen);
}

void initscrol(scr * s){
s->camera.x=0;
s->camera.y=0;
s->camera.w=1300;
s->camera.h=705;
s->level=1;
}










