#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main ( int argc, char** argv )
{
    //Init de la SDL
    SDL_Init( SDL_INIT_VIDEO );

    // On crée une fenêtre
    SDL_Surface* ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

   
    //On charge Mario
    SDL_Surface* alpha = IMG_Load("alpha.bmp");

   

    // La position absolue de alpha
    SDL_Rect posalphaAbs;
    posalphaAbs.x = 200;
    posalphaAbs.y = 300-(alpha->h);

    // La position relative de alpha
    SDL_Rect posalphaRel;
    posalphaRel.x = -50;
    posalphaRel.y = 0;

    // Boucle principale du programme
    int fin = 0;
    while (!fin)
    {
        // Gestion des evenements
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                // Quand on ferme la fenetre
            case SDL_QUIT:
                fin = 1;
                break;

                // Quand on appuie sur une touche
            case SDL_KEYDOWN:
                {
                    // ECHAP
                    if (event.key.keysym.sym ==SDLK_RIGHT)
                        posalphaRel.x++;
                    break;
                }
            }
        }

        

            if(posalphaRel.x>=50)
            {
                posalphaRel.x=-50;
            }

            //On met à "0" les pos abs:
            posalphaAbs.x = 200;
            posalphaAbs.y = 300-(alpha->h);

            //On calcule la valeur relative de y:
            posalphaRel.y=(-0.04*(posalphaRel.x*posalphaRel.x)+100);

            //On calcule maintenant les valeurs abs
            posalphaAbs.x = posalphaAbs.x + posalphaRel.x+50;
            posalphaAbs.y = posalphaAbs.y - posalphaRel.y;

        //Intervalle de 10ms
        SDL_Delay(10);

        // FIN EVOLUTION

        // DESSIN

        // On vide l'ecran
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_BlitSurface(mario, 0, ecran, &posalphaAbs);

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
        SDL_Flip(ecran);
    }

    // Soulageons la memoire !
    
    SDL_FreeSurface(alpha);

    SDL_Quit();

    return 0;
}


