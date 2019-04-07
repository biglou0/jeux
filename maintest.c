#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define WIDTH 1000
#define HEIGHT 600
#include "jeux.h"

int main ( int argc, char* argv[] )
{
        perso p1;
        scrol s;
       
        SDL_Surface *ecran = NULL,*back=NULL,*back2=NULL,*back3=NULL;
        SDL_Surface *pers[6];
     
        SDL_Rect positionback,positioncap,positionback3,positionback2;
        
        positionback.x=0;
        positionback.y=0;
     
        
        loadimg(&p1);
        back= IMG_Load("back.png");
        //back2= IMG_Load("Calque 6.png");
        //back3= IMG_Load("Calque 6.png");

       
       // SDL_BlitSurface(back1,NULL, ecran,&positionback1);

        //SDL_BlitSurface(back,NULL, ecran,&positionback);
       
        SDL_Event event;
        int gameover = 1;
        int test=0,test2=0;
        int keys[323] = {0};
	
        init_perso(&p1) ;

        init_camera(&s); 
        SDL_Init(SDL_INIT_VIDEO);

        ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

        SDL_WM_SetCaption("fairry tail ", NULL);
        
test=0;

        SDL_EnableKeyRepeat(100,100);
        while(gameover)
        {
	
        
                while(SDL_PollEvent(&event)){
                
                                          switch(event.type)
                        {
                        case SDL_QUIT:
                                gameover = 0;
                                break;
                       case SDL_KEYDOWN:
				keys[event.key.keysym.sym] = 1;				
				break;

			case SDL_KEYUP:
				keys[event.key.keysym.sym] = 0;
				
				break;
}
                                 if(keys[SDLK_LEFT])
{
test=1;
if(collision_p1(back,p1,s)==0)
{

                            updateperso(&p1,test);
                            set_camera_left(&s,&p1,test);
}
if(collision_p1(back,p1,s)==1)

{ 
updateperso(&p1,2);
set_camera_right(&s,&p1,2);


}


                             //SDL_BlitSurface(back1,  &(s.positioncamera), ecran, &positionback1); 


               
                            //test=1;







                        }
                                 if(keys[SDLK_RIGHT])
{
test=2;
if(collision_p1(back,p1,s)==0)
{
                            
                            updateperso(&p1,test);
                            set_camera_right(&s,&p1,test);

}

 if(collision_p1(back,p1,s)==1)

{ 
updateperso(&p1,1);
set_camera_left(&s,&p1,1);



}
            


                           //SDL_BlitSurface(back1,  &(s.positioncamera), ecran, &positionback1);
                                                          //test==2;
                           



                        }
                                if(keys[SDLK_UP])
{
                           test=3; 
test2=0;
                            if(collision_p1(back,p1,s)==0)
{
                            updateperso(&p1,test);
                            set_camera_up(&s,&p1,test);
}
if(collision_p1(back,p1,s)==1)

{ 
updateperso(&p1,4);
set_camera_down(&s,&p1,4);


}

                            //SDL_BlitSurface(back1, &(s.positioncamera), ecran, &positionback1);
                            //test==3;



                       }
                                  if(keys[SDLK_DOWN])
{
                        
                           
test=4;
                           
                           if(collision_p1(back,p1,s)==0)
{ 
                            updateperso(&p1,test);
                            set_camera_down(&s,&p1,test);
                                                         
}
if(collision_p1(back,p1,s)==1)

{ 
updateperso(&p1,3);
set_camera_up(&s,&p1,3);


}
                            //SDL_BlitSurface(back1, &(s.positioncamera), ecran, &positionback1);
                            //test==4;




                       }
                  



                           


SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
//updateperso(&p1,&p2,test,test2);

SDL_BlitSurface(back,NULL,ecran,&positionback);  
SDL_BlitSurface(back,&(s.positioncamera), ecran,&positionback);  



//SDL_BlitSurface(s.camera,&(s.positioncamera), ecran,NULL);


displayperso(p1,ecran,test) ;



 SDL_Flip(ecran);
}
}


perso_freeperso1(&p1);

        SDL_Quit();
        return 0;
}
                       

