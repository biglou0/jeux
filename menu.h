#define LARGEUR 1300
#define HAUTEUR 705



typedef struct 
{
	int vie; 
	SDL_Surface *image ;
	SDL_Rect pos_es;

}ennemi;


typedef struct var var;
struct var {
SDL_Surface* screen;
SDL_Rect screenrect;
SDL_Surface * backg;
SDL_Rect backgrect;
SDL_Surface* play;
SDL_Rect playrect;
SDL_Surface* setting;
SDL_Rect settingrect;
SDL_Surface* leave;
SDL_Rect leaverect;
SDL_Surface* Hplay;
SDL_Surface* Hset;
SDL_Surface* Hleave;
SDL_Surface* tmp;
SDL_Event event;
SDL_Event eevent;
SDL_Surface* flowb;
SDL_Surface* menuu;
SDL_Rect menub;
SDL_Surface* backb;
SDL_Rect backr;
SDL_Surface* on;
SDL_Surface* off;
SDL_Rect setm;
SDL_Rect sets;
SDL_Rect setshadow;
SDL_Surface* levelup;

int son;
int music;
int shadow;
int run;
int menu;
int etat;
int game;
int settingg;
int level;
int vie;
int keys;
int time;
};














void loadimg(var * act);
void blit(var * act );
void freesur(var * act , ennemi *es );
void initialisation(var *act );
void action(var * act );
void fsettings(var * act);
void backgroundandscrolling(var * act);


