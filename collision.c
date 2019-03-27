#include "header.h"

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
	SDL_Color color;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) pSurface->pixels ;

	//offset by y
	pPosition += ( pSurface->pitch * y ) ;

	//offset by x
	pPosition += ( pSurface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}

int collision_perpri(BACKGROUND *bg,PERSO_PRINCIPALE *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[7];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*1/3 ,per->position.y ); //head 1/3 x
	couleur[1] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*2/3 ,per->position.y ); //head 2/3 x
	couleur[2] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + (int)per->position.h/2 ); //hand right
	couleur[3] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + (int)per->position.h/2 );// hand left
	couleur[4] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + per->position.h );// foot left
	couleur[5] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + per->position.h );// foot right
	couleur[6] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w/2,per->position.y + per->position.h ); // foot mid
	
	for(i=0;i<7;i++)
	{
		if((couleur[i].r == 255) && ((couleur[i].g == 255) && (couleur[i].b == 255))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
		return 1;
	else return 0;
}

int collision_enigme(BACKGROUND *bg,PERSO_PRINCIPALE *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[7];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*1/3 ,per->position.y ); //head 1/3 x
	couleur[1] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*2/3 ,per->position.y ); //head 2/3 x
	couleur[2] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + (int)per->position.h/2 ); //hand right
	couleur[3] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + (int)per->position.h/2 );// hand left
	couleur[4] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + per->position.h );// foot left
	couleur[5] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + per->position.h );// foot right
	couleur[6] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w/2,per->position.y + per->position.h ); // foot mid
	
	for(i=0;i<7;i++)
	{
		if((couleur[i].r == 0) && ((couleur[i].g == 255) && (couleur[i].b == 255))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
		return 1;
	else return 0;
}
int collision_ENDLV(BACKGROUND *bg,PERSO_PRINCIPALE *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[7];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*1/3 ,per->position.y ); //head 1/3 x
	couleur[1] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w*2/3 ,per->position.y ); //head 2/3 x
	couleur[2] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + (int)per->position.h/2 ); //hand right
	couleur[3] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + (int)per->position.h/2 );// hand left
	couleur[4] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + per->position.h );// foot left
	couleur[5] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + per->position.h );// foot right
	couleur[6] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w/2,per->position.y + per->position.h ); // foot mid
	
	for(i=0;i<7;i++)
	{
		if((couleur[i].r == 0) && ((couleur[i].g == 255) && (couleur[i].b == 0))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
		return 1;
	else return 0;
}
int collision_sol(BACKGROUND *bg,PERSO_PRINCIPALE *per) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[3];
	//pixel color perso pri
	couleur[0] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x , per->position.y + per->position.h );// foot left
	couleur[1] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + per->position.w ,per->position.y + per->position.h );// foot right
	couleur[2] = GetPixel (bg->bg_collision,bg->scroll.x + per->position.x + (int)per->position.w/2,per->position.y + per->position.h ); // foot mid
	
	for(i=0;i<3;i++)
	{
		if((couleur[i].r == 255) && ((couleur[i].g == 0) && (couleur[i].b == 0))) // a changer
		{
			verif=1;
			break;
		}
	}
	if (verif==1)
		return 1;
	else return 0;
}

int collision_top(PERSO_TOP_VIEW *top) // collision personage principale avec obstacle
{
	int verif=0;
	int i;
	SDL_Color couleur[5];
	//pixel color perso pri
	couleur[0] = GetPixel(top->bg_col,top->position.x+50,top->position.y+50);// foot left
	couleur[1] = GetPixel(top->bg_col,top->position.x,top->position.y);
	couleur[2] = GetPixel(top->bg_col,top->position.x+25,top->position.y+25);
	couleur[3] = GetPixel(top->bg_col,top->position.x+50,top->position.y);
	couleur[4] = GetPixel(top->bg_col,top->position.x,top->position.y +50);
	for(i=0;i<5;i++)
	{
		if((couleur[i].r == 0) && ((couleur[i].g == 255) && (couleur[i].b == 0))) // a changer
		{
			verif=1;// mexico
			break;
		}
		if((couleur[i].r == 0) && ((couleur[i].g == 255) && (couleur[i].b == 255))) // a changer
		{
			verif=3;//tokyo
			break;
		}
		if((couleur[i].r == 255) && ((couleur[i].g == 0) && (couleur[i].b == 255))) // a changer
		{
			verif=2;//mombay
			break;
		}
		if((couleur[i].r == 255) && ((couleur[i].g == 255) && (couleur[i].b == 0))) // a changer
		{
			verif=4;// newyork
			break;
		}
	}
	return verif;
}

