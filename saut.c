#include "saut.h"

int rida(int r)
{

   
        r = r + 8;
    
    return r;
}

void saut()
{
    SDL_Surface *screen = NULL, *image = NULL, *image1 = NULL;
    SDL_Rect rect, rect1;//Pour indiquer les cordonnées de rect et rect1

    int continuer;
    SDL_Event event;
    int test;
    test = 0;
    continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);//démarrage de la SDL

    screen = SDL_SetVideoMode(960, 539, 32, SDL_HWSURFACE);//on tente d'ouvrirUNe fênetre (allocation du surface)
    SDL_WM_SetCaption("Saut By Me",NULL);//Mettre le titre du fênetre
    image = IMG_Load("per2.png");//charger l'image de personnage 
    image1 = IMG_Load("1.png");//charger le background
    //position du background
    rect1.x = 0;
    rect1.y = 10;
    //position du personnage
    rect.x = 15;
    rect.y = 185;

    while (continuer)
    {

        SDL_BlitSurface(image1, NULL, screen, &rect1);//coller la surface sur l'ecran 
        SDL_BlitSurface(image, NULL, screen, &rect);//coller la surface sur l'ecran 
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
        {

            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                if (test == 0)
                {
                    do
                    {
                        test++;
                        rect.y--;
                       

                    } while (test < 300);
                    if (test==300)
                    {
                        SDL_Delay(100);
                    }
                }
                break;
            }
        }
        }
            if (test == 300 && rect.y < 200)
            {
                rect.y = rida(rect.y);
            }
            if (rect.y == 200)
            {
                test = 0;
            }

            SDL_BlitSurface(image, NULL, screen, &rect);//coller la surface sur l'ecran 
            
       

        SDL_Flip(screen);//mettre à jour l'écran
    }

    SDL_FreeSurface(screen);//libération	
    SDL_FreeSurface(image);//libération
    SDL_FreeSurface(image1);//libération
    SDL_Quit();//arrêt de la SDL
}
