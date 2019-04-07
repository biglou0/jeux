#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED
#include"animation.h"
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct scrol
{
SDL_Rect positioncamera ;
SDL_Surface *camera;
} scrol ;


void init_camera(scrol *s) ;
void set_camera_left(scrol *s,perso *p1,int test);
void set_camera_right(scrol *s,perso *p1,int test);
void set_camera_up(scrol *s,perso *p1,int test);
void set_camera_down(scrol *s,perso *p1,int test);




#endif
