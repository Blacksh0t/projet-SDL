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

int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *texte = NULL, *image1 = NULL;
    SDL_Rect rect1;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {18, 12, 0}, couleurBlanche = {225, 25, 75};
    int ok = 1;
    int scoreActuel = 0, scorePrecedent = 0, rida = 0; /*initialisation*/
    char score[20] = ""; /* Tableau de char suffisamment grand */
    image1 = IMG_Load("1.png");
    SDL_Init(SDL_INIT_VIDEO);//démarrage de la SDL
    TTF_Init();//POUR LIRE les textos
    rect1.x = 0;
    rect1.y = 0;
 
    
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);/*choix du mode vidéo */
    SDL_WM_SetCaption("Score", NULL);/*pour metre le titre du fênetre*/

    /* Chargement de la police */
    police = TTF_OpenFont("SCOREBOARD.ttf", 27);

    /* Initialisation du score et du texte */
    scoreActuel = SDL_GetTicks();
    sprintf(score, "Mon Score : %d", rida);
    texte = TTF_RenderText_Shaded(police, score, couleurNoire, couleurBlanche);

    while (ok)
    {
        SDL_BlitSurface(image1, NULL, ecran, &rect1);//coller la surface sur l'ecran 
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                ok = 0;
                break;
                
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));//remplissage de la surface avec du blanc

        scoreActuel = SDL_GetTicks();
        if (scoreActuel - scorePrecedent >= 100 ) /* Si 100 ms au moins se sont écoulées */
        {
            rida += 5; /* On rajoute 5 points  */
            sprintf(score, "Mon Score : %d", rida); /* On écrit dans la chaîne "score" le nouveau score */
            SDL_FreeSurface(texte); /* On supprime la surface précédente(update) */
            texte = TTF_RenderText_Shaded(police, score, couleurNoire, couleurBlanche); /* On écrit la chaîne score dans la SDL_Surface */
            scorePrecedent = scoreActuel; /* On met à jour le scorePrecedent */
        }
                else
        SDL_Delay(1000-(scoreActuel - scorePrecedent)) ;

        position.x = 0;
        position.y = 0;
SDL_BlitSurface(image1, NULL, ecran, &rect1);//coller la surface sur l'ecran 
        SDL_BlitSurface(texte, NULL, ecran, &position);//coller la surface sur l'ecran 
         /* Blit du texte */
        SDL_Flip(ecran);//mettre à jour l'écran
    }

    TTF_CloseFont(police);
    TTF_Quit();
     
    SDL_FreeSurface(texte);//libération
SDL_FreeSurface(image1);//libération
    SDL_Quit();//arrêt de la SDL

    return EXIT_SUCCESS;
}
