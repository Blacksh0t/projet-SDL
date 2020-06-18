
#include "dep.h"

 void initialiser (Objet *perso ) 
 {
  perso->img=IMG_Load("detective.png") ;//load l'image de personnage
  perso->pos.x=20 ;
  perso->pos.y=200 ; //position du personnage
 }

