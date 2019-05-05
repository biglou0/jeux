typedef struct 
{
SDL_Event ev;
SDL_Rect camera;
int level;
SDL_Rect persorect;
SDL_Surface * perso;
}scr;

void scrolling(scr * s , int * game, int * run,SDL_Surface* screen,SDL_Surface* backg1,SDL_Surface* backg2,SDL_Surface* backg3);
void initscrol(scr * s);

