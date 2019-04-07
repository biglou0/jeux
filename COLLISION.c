#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "COLLISION.h"

#define true 1
#define false 0
typedef int bool;



bool Collision(SDL_Rect box1,SDL_Rect box2)
{
   if((box2.x >= box1.x + box1.w)      // trop à droite
	|| (box2.x + box2.w <= box1.x) // trop à gauche
	|| (box2.y >= box1.y + box1.h) // trop en bas
	|| (box2.y + box2.h <= box1.y))  // trop en haut
          return 0; 
   else
          return 1; 
}



