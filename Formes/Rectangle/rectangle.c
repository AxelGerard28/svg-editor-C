#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

Rectangle rectangle()
{
    Rectangle r;
    int placement;
    printf("tu as choisi le rectangle\n");
    printf("veux tu placer le rectangle sur le repere ? (1 pour oui, 0 pour non)");
    scanf("%d", &placement);
    
    if (placement == 1)
    {
        printf ("choisissons ses coordonnés\n");
        printf ("quel coordonné veux tu pour ton x ?\n");
        scanf ("%d", &r.x);
        
        printf ("quel coordonné veux tu pour ton y ?\n");
        scanf ("%d", &r.y);

        printf("quel longueur de rectangle veut tu ?\n");
        scanf("%d",&r.longueur);

        printf("quel largeur de rectangle veut tu ?\n");
        scanf("%d",&r.largeur);

        printf("donc ton rectangle est en\n x = %d\n",r.x);
        printf(" y = %d\n",r.y);
        printf("a une longueur\n l = %d\n",r.longueur);
        printf("a une largeur\n L = %d\n",r.largeur);
        
    
    }
    return r;
}
