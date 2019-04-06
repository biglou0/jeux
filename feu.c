#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*image1 = NULL,*image2=NULL;
    SDL_Rect positionFond,position1,position2;

    positionFond.x = 200;
    positionFond.y = 0;
  position1.x =20;
   position1.y = 300;
position2.x =10;
   position2.y = 200;


    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("/home/amina/caisse-ConvertImage.bmp");
 image1 = SDL_LoadBMP("/home/amina/caisse_ok.bmp");
 image2 = SDL_LoadBMP("/home/amina/Downloads/mur.bmp");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
  SDL_BlitSurface(image1, NULL, ecran, &position1);
SDL_BlitSurface(image2, NULL, ecran, &position2);
	

    SDL_Flip(ecran);
    pause();

    SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);

    SDL_Quit();


    SDL_Quit();

    return EXIT_SUCCESS;
}




