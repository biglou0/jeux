typedef struct 
{
SDL_Rect over;
TTF_Font * font;
SDL_Surface *ch;
SDL_Surface *ba;
SDL_Event event;
int pause;
}condition;


void initcond(condition * a) ;
void cond(int level , condition* c,int  vie,SDL_Surface* screen);

