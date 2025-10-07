#include <stdio.h>
#include <stdlib.h>
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
    printf(RED"selectionne une forme:\n");
    printf(GREEN" -1 pour un cercle\n -2 pour une ellipse\n -3 pour un carré\n -4 pour un rectangle\n");
    printf(" -5 pour une ligne\n -6 pour un enchainement de lignes\n -7 pour un polygone\n -8 pour une trajectoire\n");
    printf(" -9 pour les groupes\n"RESET);
    scanf(" %d", &formes);

    switch (formes)

    {
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
        printf("ceci n'existe pas\n");
        break;
    }
}