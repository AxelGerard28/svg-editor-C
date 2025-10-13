#include <stdio.h>
#include <stdlib.h>
#include "cercle.h"

#include "structure.h"

Cercle cercle()
{
    Cercle c;
    int placement;
    printf("tu as choisi le cercle\n");
    printf("veux tu placer le cercle sur le repere ? (1 pour oui, 0 pour non)");
    scanf("%d", &placement);
    
    if (placement == 1)
    {
        printf ("choisissons ses coordonnés\n");
        printf ("quel coordonné veux tu pour ton x ?\n");
        scanf ("%d", &c.x);
        
        printf ("quel coordonné veux tu pour ton y ?\n");
        scanf ("%d", &c.y);

        printf("quel rayon veux tu ?\n");
        scanf("%d",&c.rayon);

        printf("donc ton cercle est en\n x = %d\n",c.x);
        printf(" y = %d\n",c.y);
        printf("et a un rayon r = %d\n",c.rayon);
        
    
    }
    return c;
}
