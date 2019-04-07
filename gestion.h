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
SDL_Rect timing;
TTF_Font *fonttexte;
SDL_Surface *chrono;
SDL_Color couleurtexte , couleur ;
}gestionn;


void initgestiondeviescore(gestionn * a);
void gestiondevieetscore(gestionn * a , int vie , int keys ,SDL_Surface* screen);
void freesurfacesdegestion(gestionn *a);
