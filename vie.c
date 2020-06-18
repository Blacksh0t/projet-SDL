#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "vie.h"


int collisionbb( SDL_Rect ridaJ , SDL_Rect rida1j  )
{
 int x ; 
if ( ((ridaJ.y+ridaJ.h>=rida1j.y)&&(ridaJ.y<=rida1j.y+rida1j.h)&&(ridaJ.x+ridaJ.w>=rida1j.x)&&(ridaJ.x<=rida1j.x+rida1j.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}
void initialiservie(vie *vie)
{

vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("1.png");
vie->fond2 = IMG_Load("2.png");
vie->fond3 = IMG_Load("3.png");
vie->fond4 = IMG_Load("4.png");

}

void affichervie(vie *vie,SDL_Rect *ridaJ , SDL_Rect rida1j,SDL_Surface *ecran , int *i )
{
 int k=collisionbb( (*ridaJ) , rida1j );

if(k==1)
{
(*ridaJ).x=0;
(*i)++;
}

if((*i)==0)
{

SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);//collage
SDL_Flip(ecran);//Mise à Jour de l'écran
}

else if((*i)==1)
{

SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==2)
{
//(*ridaJ).x=0;
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==3)
{
//(*ridaJ).x=0;
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
//strsep(5);
}

