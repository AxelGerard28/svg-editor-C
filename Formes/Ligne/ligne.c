#include <stdio.h>
#include <stdlib.h>
#include "ligne.h"

Ligne ligne()
{
    Ligne l;
    int placement;
    printf("tu as choisi la ligne\n");
    printf("veux tu placer la ligne sur le repere ? (1 pour oui, 0 pour non)");
    scanf("%d", &placement);
    
    if (placement == 1)
    {
        printf ("choisissons ses coordonnés\n");
        printf ("quel coordonné veux tu pour ton x au premier point ?\n");
        scanf ("%d", &l.x1);
        
        printf ("quel coordonné veux tu pour ton y au premier point?\n");
        scanf ("%d", &l.y1);

        printf("quel coordonné veux tu pour ton x au deuxieme point ?\n");
        scanf("%d",&l.x2);

        printf("quel coordonné veux tu pour ton y au deuxieme point ?\n");
        scanf("%d",&l.y2);

        printf("donc ton premier point de la ligne ces ces coordonné :\n x = %d\n",l.x1);
        printf(" y = %d\n",l.y1);
        printf("et le deuxieme point de la ligne a ces coordonné ;\n x = %d\n",l.x2);
        printf(" y = %d\n",l.y2);
        
    
    }
    return l;
}
