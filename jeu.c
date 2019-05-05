#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "perso.h"
#include "jeu.h"
#include "text.h"

int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
	Uint32 t_prev, dt=1; 
	
	perso pers;
	Background Backg;
	Text txt;
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	
	TTF_Font *police = NULL;

	if(loadpersoImages(&pers) == -1) {
		printf("Erreuer Chargement Voiture Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}
	
	if(loadFont(&police) == EXIT_FAILURE){
		printf("Erreuer Chargement Font ttf\n");
		return(-1);
	}

	initBackground(&Backg);
	initperso(&pers);
	initText(&txt);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {
		t_prev=SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			// check for messages
			switch (event.type) {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				pers.moving=1; //lets move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				pers.moving=0;
				pers.velocity=0;
				break;
			}
			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
			if(keysHeld[SDLK_SPACE]) {
				pers.velocity=5;
				pers.direction=0; //right direction
				pers.acceleration+=0.005;
				//moveVoiture(&car,&Backg,dt);
				i++;}
			else
			{if(pers.acceleration>0)
			pers.acceleration-=0.001;
			
			}
			if(keysHeld[SDLK_CLEAR]) {
			pers.acceleration-=0.001;
			
			}
			moveperso(&pers,&Backg,dt);
		} // end of message processing
		i=i%4;
		//Blit the bachground to the backbuffer
		blitBackground(&Backg,screen);

		//Blit Voiture to screen
		if(!pers.moving)
			i=0;
		if(pers.direction == 0)
			SDL_BlitSurface(pers.image[i],NULL,screen,&pers.position);
			
		displayText(police,&txt,screen,pers,Backg,0);
		
		SDL_Flip(screen);
		dt=SDL_GetTicks()-t_prev;
		if((1000/FPS)>dt)
		SDL_Delay(1000/FPS-dt);
		
	}

	                // free loaded bitmap

	freeperso(&pers);
	freeBackground(&Backg);
	TTF_CloseFont(police);
	return(0);
}
