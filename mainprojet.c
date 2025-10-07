#include <stdio.h>
#include <stdlib.h>


typedef enum
{
    SQUARE,
    RECTANGLE,
    CIRCLE
}TypesFormes;

typedef struct
{
    TypesFormes type;
    int x;
    int y;
    int h;
    int l;
    int r;
}Dimensions;

int main(void)
{
    int formes;
    printf("what do you want ?\n");
    printf(" -1 pour un cercle\n -2 pour une ellipse\n -3 pour un carré\n -4 pour un rectangle");
    printf(" -5 pour une ligne\n -6 pour un enchainement de lignes\n -7 pour un polygone\n -8 pour une trajectoire\n");
    printf(" -9 pour les groupes\n");
    scanf(" %d", &formes);

    switch (formes)
    {
    case 1:
        printf("tu as choisi un cercle\n");
        break;
    case 2:
        printf("tu as choisi une ellipse\n");
        break;
    case 3:
        printf("tu as choisi un carré\n");
        break;
     case 4:
        printf("tu as choisi un rectangle\n");
        break;
    case 5:
        printf("tu as choisi une ligne\n");
        break;
    case 6:
        printf("tu as choisi un enchainement de lignes\n");
        break;
    case 7:
        printf("tu as choisi un polygone\n");
        break;
    case 8:
        printf("tu as choisi une trajectoire\n");
        break;
    case 9: 
        printf("tu as choisi une trajectoire\n");
        break;
    default:
        printf("ceci n'existe pas\n");
        break;
    }
}