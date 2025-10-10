#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "formes.h"

Formes lesformes()
{
    printf("hello,world\n");
    Carre carre();
{
    Carre c;
    int placement;
    printf("tu as choisi le carre\n");
    printf("veux tu placer le carre sur le repere ? (1 pour oui, 0 pour non)");
    scanf("%d", &placement);
    
    if (placement == 1)
    {
        printf ("choisissons ses coordonnés\n");
        printf ("quel coordonné veux tu pour ton x ?\n");
        scanf ("%d", &c.x);
        
        printf ("quel coordonné veux tu pour ton y ?\n");
        scanf ("%d", &c.y);

        printf("quel taille de carré veut tu ?\n");
        scanf("%d",&c.longueur);

        printf("donc ton carré est en\n x = %d\n",c.x);
        printf(" y = %d\n",c.y);
        printf("et a une taille\n l = %d\n",c.longueur);
        
    
    }
    return CARRE;
}

}