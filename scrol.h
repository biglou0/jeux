typedef struct 
{
SDL_Event ev;
SDL_Rect camera;
int level;

}scr;

void scrolling(scr * s , int * game, int * run,SDL_Surface* screen);
void initscrol(scr * s);

