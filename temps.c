/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//je veux mettre deux compteur(rida,rida1) le 1ère c'est pour les secondes et le 2éme pour les minutes .. lorsque rida=60 alors on ajout 1 à rida1
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *texte = NULL ,*image1 = NULL;
    SDL_Rect position;
SDL_Rect rect1;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {119, 181, 254};
    int ok = 1;
    int tempsActuel = 0, tempsPrecedent = 0, rida = 0,rida1 = 0; /*initialisation*/
    char Temps[200] = ""; /* Tableau de char suffisamment grand */
image1 = IMG_Load("1.png");
    SDL_Init(SDL_INIT_VIDEO);//démarrage de la SDL	
    TTF_Init();
rect1.x = 0;
    rect1.y = 0;
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /*choix du mode vidéo */ 
    SDL_WM_SetCaption("Temps ", NULL);/*pour metre le titre du fênetre*/

    /* Chargement de la police */
    police = TTF_OpenFont("Tempus Fugit.ttf", 35);//Chargem€nt de textos

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(Temps, "Temps : %d:%d", rida1,rida);
    texte = TTF_RenderText_Shaded(police, Temps, couleurNoire, couleurBlanche);

    while (ok)
    {
SDL_BlitSurface(image1, NULL, ecran, &rect1);
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                ok = 0;
                break;
                
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100) /* Si 100 ms au moins se sont écoulées */
        {
            rida += 1; /* On rajoute 1s au rida */

if (rida==60)
{
rida1 +=1;//si les secondes égale à 60 on ajoute 1 minute
rida=0;
}
            sprintf(Temps, "Temps : %d:%d", rida1,rida); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(texte); /* On supprime la surface précédente */
            texte = TTF_RenderText_Shaded(police, Temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }
                else
        SDL_Delay(1000-(tempsActuel - tempsPrecedent)) ;

        position.x = 420;
        position.y = 0;
SDL_BlitSurface(image1, NULL, ecran, &rect1);//coller la surface sur l'ecran
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);//mise à jour du l'ecran

    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);//Libération de la surface
SDL_FreeSurface(image1);//libération
    SDL_Quit();//Arrêt de La SDL

    return EXIT_SUCCESS;
}
