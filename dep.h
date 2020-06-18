#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;

 void initialiser (Objet *perso )  ;