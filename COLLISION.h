
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>


#ifndef COLLISION_H_
#define COLLISION_H_


typedef struct AABB
{
  int x;
  int y;
  int w;
  int h;
}AABB;

typedef int bool;

bool Collision(SDL_Rect box1,SDL_Rect box2);








#endif 

