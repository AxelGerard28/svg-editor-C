#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"

Ellipse ellipse()
{
    Ellipse e;
    int placement;
    printf("tu as choisi une ellipse\n");
    printf("veux tu placer ton ellipse sur le repere ? (1 pour oui, 0 pour non)");
    scanf("%d", &placement);
    
    if (placement == 1)
    {
        printf ("choisissons ses coordonnés\n");
        printf ("quel coordonné veux tu pour ton x ?\n");
        scanf ("%d", &e.x);
        
        printf ("quel coordonné veux tu pour ton y ?\n");
        scanf ("%d", &e.y);

        printf("quel rayon-x veux tu ?\n");
        scanf("%d",&e.rayonx);

        printf("quel rayon-y veux tu ?\n");
        scanf("%d",&e.rayony);

        printf("donc ton ellipse est en\n x = %d\n",e.x);
        printf(" y = %d\n",e.y);
        printf("a un rayon-x r = %d\n",e.rayonx);
        printf("et a un rayon-y r = %d\n",e.rayony);
        
    
    }
    return e;
}