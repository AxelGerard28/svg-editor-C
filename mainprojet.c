#include <stdio.h>
#include <stdlib.h>
#include "Formes/Formes/formes.h"
#include "Formes/structure.h"

#include "Formes/Cercle/cercle.h"
#include "Formes/Rectangle/rectangle.h"

#include "Formes/Ellipse/ellipse.h"
#include "Formes/Ligne/ligne.h"
#include "Formes/Enchlignes/enchlignes.h"
#include "Formes/Polygone/polygone.h"
#include "Formes/Trajectoire/trajectoire.h"
#include "Formes/Groupe/groupe.h"



#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

int main(void)
{
    int formes;
    printf(RED "Sélectionne une forme (0 pour quitter) :\n" RESET);
    printf(GREEN " 1  - Cercle\n 2  - Ellipse\n 3  - Carré\n 4  - Rectangle\n"
                     " 5  - Ligne\n 6  - Enchaînement de lignes\n 7  - Polygone\n"
                     " 8  - Trajectoire\n 9  - Groupe\n" RESET);
    printf("ton choix :");
    scanf(" %d", &formes);
    
    switch (formes)
    {
    case 0:
        lesformes();
        break;
    case 1:
        cercle();
        break;
    case 2:
        ellipse();
        break;
    case 3:
        carre();
        break;
     case 4:
        rectangle();
        break;
    case 5:
        ligne();
        break;
    case 6:
        enchlignes();
        break;
    case 7:
        polygone();
        break;
    case 8:
        trajectoire();
        break;
    case 9: 
        groupe();
        break;
    default:
        printf("ceci n'existe pas : %d\n", formes);
        break;
   }
}