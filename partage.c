
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage.h"





void initialiser(Objet *perso,Objet *map, Objet *wood, Objet *boat, Objet *map2, Objet *failed)
{

  SDL_WM_SetCaption("Partage By Rida", NULL);//mettre le titre du fênetre

  failed->img = IMG_Load("01.png");
  failed->pos.x = 0;
  failed->pos.y = 0;

  map2->img = IMG_Load("backgound.png");// Load Background page1
  map2->pos.x =0 ;
  map2->pos.y = 0;
  map2->pos.h = 500;
  map2->pos.w = 1280/2;

  map->img = IMG_Load("backgound.png");// Load Background page2
  map->pos.x = 0;
  map->pos.y = 0;
  map->pos.h = 465;
  map->pos.w = 1280/2;

  wood->img = IMG_Load("per1.png");// Load caractere de page 1
  wood->pos.x = 0;
  wood->pos.y = 330;

  perso->img = IMG_Load("per2.png");// Load Personnage de page 2
  perso->pos.x = 600;
  perso->pos.y = 170;

}

void setup(SDL_Surface *screen, Objet *map, Objet *wood, Objet *boat, Objet *map2, Objet *perso)
{
  SDL_Rect pos1,pos2 ;// pour indiquer les positions de pos1 et pos2
 pos1.x=0 ;
 pos1.y=0 ;

 pos2.x=1280/2 ;
 pos2.y=0 ;


  SDL_BlitSurface(map->img,&(map->pos), screen,&pos2);

//collage 
  SDL_BlitSurface(map2->img, &(map2->pos), screen,&pos1);
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  SDL_BlitSurface(perso->img, NULL, screen, &(perso->pos));

  SDL_Flip(screen);//metre à jour l'écran
}

void affichage(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, Objet *map2,Objet *perso)
{
   SDL_Rect pos1,pos2 ;
 pos1.x=0 ;
 pos1.y=0 ;

 pos2.x=1280/2 ;
 pos2.y=0 ;
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));//remplissage de la surface avec du blanc
//collage
  SDL_BlitSurface(map->img, &(map->pos), screen, &pos2);
  SDL_BlitSurface(map2->img, &(map2->pos), screen,&pos1);
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  SDL_BlitSurface(perso->img, NULL, screen, &(perso->pos));

  
  SDL_Flip(screen) ;
}

void scrolling_droit(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x <= mapw - 1368)
  {
    map->pos.x += 20;
    boat->pos.x -= 20;
    (pos->x) += 20;
  }
}

void scrolling_gauche(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x >= 20)
  {
    map->pos.x -= 20;
    boat->pos.x += 20;
    (pos->x) -= 20;
  }
}

void evenement(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, int *running, SDL_Rect *pos, Objet *map2,Objet *perso)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:

    switch (event.key.keysym.sym)

    {

    case SDLK_RIGHT: // Flèche droite

      scrolling_droit(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2,perso);

      SDL_Flip(screen);

      break;

    case SDLK_LEFT: // Flèche gauche
      scrolling_gauche(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2,perso);

      SDL_Flip(screen);

      break;
    case SDLK_a: // Flèche gauche
      scrolling_gauche(screen, map2, pos, boat);
      affichage(screen, boat, wood, map, map2,perso);

      SDL_Flip(screen);

      break;
    case SDLK_z: // Flèche gauche
      scrolling_droit(screen, map2, pos, boat);
      affichage(screen, boat, wood, map, map2,perso);

      SDL_Flip(screen);//mettre à jour l'écran

      break;
    }

    break;
  }
}

void deplacement_objet(Objet *objet, int *running)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case SDLK_DOWN:
      objet->pos.y += 2;
      break;
    case SDLK_UP:
      objet->pos.y -= 2;
      break;
    case SDLK_RIGHT:
      if (objet->pos.x < (1368 - objet->img->w))
        objet->pos.x += 7;
      break;
    case SDLK_LEFT:
      objet->pos.x -= 7;
      break;
    }
  }
}

void free_memory(Objet *boat, Objet *wood, Objet *map, Objet *map2)
{
  SDL_FreeSurface(boat->img);//libérer de la mémoire 
  SDL_FreeSurface(wood->img);//libérer de la mémoire 
  SDL_FreeSurface(map->img);//libérer de la mémoire 
  SDL_FreeSurface(map2->img);//libérer de la mémoire 

  SDL_Quit();//Arrêt de la SDL
}
