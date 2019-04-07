#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED
typedef struct perso
{
SDL_Rect positionperso ; 
int val1; 
int val2;
SDL_Surface *pers[6]; 
} perso ;

 typedef struct scrol
{
SDL_Rect positioncamera ;
SDL_Surface *camera;
} scrol ;

void init_perso(perso *p1) ;
void loadimg(perso *p1);
void updateperso(perso *p1,int test);
void displayperso(perso p1,SDL_Surface *ecran,int test);
void perso_freeperso1(perso *p1) ;
SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y);
int collision_p1(SDL_Surface *back2,perso p1,scrol s);
void init_camera(scrol *s) ;
void set_camera_left(scrol *s,perso *p1,int test);
void set_camera_right(scrol *s,perso *p1,int test);
void set_camera_up(scrol *s,perso *p1,int test);
void set_camera_down(scrol *s,perso *p1,int test);





#endif

