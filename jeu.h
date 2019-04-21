#define LARGEUR 1300
#define HAUTEUR 705
#define WIDTH 9500
#define HEIGHT 3525 
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct{
SDL_Surface* ennemi;
SDL_Rect ennemirect;
SDL_Surface* screen;

}Ennemi;
typedef struct {

SDL_Surface* image1;
SDL_Surface* image2;
SDL_Surface* image3;
SDL_Surface* image4;
SDL_Rect position1,position2,position3,position4;

}objet;
typedef struct AABB
{
  int x;
  int y;
  int w;
  int h;
}AABB;
typedef struct 
{
SDL_Rect level1;
SDL_Surface* heart;
SDL_Rect level2;
SDL_Rect level3;
SDL_Rect key1;
SDL_Surface* key;
SDL_Surface* keyon;
SDL_Rect key2;
SDL_Rect key3;

}gestionn;
typedef struct 
{
SDL_Event ev;
SDL_Rect camera;
int level;

}scr;
typedef struct personnage
{
SDL_Rect positionperso ; 
int val1; 
int val2;
SDL_Surface *pers[6]; 
} personnage ;

 typedef struct scrol
{
SDL_Rect positioncamera ;
SDL_Surface *camera;
} scrol ;
typedef struct enigmes_question
{
char reponsevrai[4];
char q[400];
char rep1[4];
char rep2[4];
}enigmes_question;


typedef struct enigme
{

enigmes_question EN[30];
int reponse;

}enigme;



typedef int bool;
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
typedef struct
 {
SDL_Surface* gamebackglvl1;
SDL_Surface* gamebackglvl2;
SDL_Surface* gamebackglvl3;
SDL_Surface* end1;
SDL_Surface* end2;
SDL_Surface* end3;
SDL_Surface* end4;
SDL_Rect backgr;
}backg;

void inti(Ennemi *e);
void affiche(Ennemi *e,SDL_Surface *screen);
int deplacement(Ennemi *e);
void animation(Ennemi *e, int direction,SDL_Surface *screen);

void init_objet(objet *o,SDL_Surface *ecran);

void afficherobjet(objet *o,SDL_Surface *ecran);


bool Collision(SDL_Rect box1,SDL_Rect box2);


void initgestiondeviescore(gestionn * a);
void gestiondevieetscore(gestionn * a , int vie , int keys ,SDL_Surface* screen; );
void freesurfacesdegestion(gestionn *a);


void scrolling(scr * s , int * game, int * run,SDL_Surface* screen);
void initscrol(scr * s);

void init_perso(personnage *p1) ;
void load(personnage *p1);
void updateperso(personnage *p1,int test);
void displayperso(personnage p1,SDL_Surface *ecran,int test);
void perso_freeperso1(personnage *p1) ;
SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y);
int collision_p1(SDL_Surface *back2,personnage p1,scrol s);
void init_camera(scrol *s) ;
void set_camera_left(scrol *s,personnage *p1,int test);
void set_camera_right(scrol *s,personnage *p1,int test);
void set_camera_up(scrol *s,personnage *p1,int test);
void set_camera_down(scrol *s,personnage *p1,int test);


int initialiser_enigmes();
void generation(enigme *E,int val);
void affichage(enigme *E ,int val);
int resolution_enigmes(char reponse_choisie[4], int val,enigme *E); 

void loading(var * act);
void blit(var * act );
void freesur(var * act , Ennemi *e );
void initialisation(var *act );
void action(var * act );
void fsettings(var * act);
void backgroundandscrolling(var * act);


void affichebackground(int level , int time ,SDL_Surface* screen, SDL_Rect * camera, backg *b);
void initbackground(backg *b);
void freesurfaces(backg *b);









