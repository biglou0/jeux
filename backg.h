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
//Mix_Music *music;
}backg;

void affichebackground(int level , int time ,SDL_Surface* screen, SDL_Rect * camera, backg *b);
void initbackground(backg *b);
void freesurfaces(backg *b);

