#include <stdio.h>
#include <stdlib.h>
#include "Formes/structure.h"

#include "Formes/Cercle/cercle.h"
#include "Formes/Rectangle/rectangle.h"
#include "Formes/Carre/carre.h"
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
    printf(GREEN " 1  - Cercle\n" 
                 " 2  - Ellipse\n"
                 " 3  - Carré\n"
                 " 4  - Rectangle\n"
                 " 5  - Ligne\n " RESET);
                  
    printf("ton choix :");
    scanf(" %d", &formes);
    
    switch (formes)
    {
    case 0:
        printf("abandon\n");
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
    default:
        printf("ceci n'existe pas : %d\n", formes);
        break;
   }
}