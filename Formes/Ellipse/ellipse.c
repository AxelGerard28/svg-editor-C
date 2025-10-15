#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"

Ellipse *create_ellipse() {
    Ellipse* ellipse = malloc(sizeof(Ellipse));
    int placement_ellipse;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║     ✨  CRÉATION D'ELLIPSE  ✨     ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📍 Veux-tu placer ton ellipse sur le repère ?\n");
    printf("   [1] Oui, je veux choisir les coordonnées\n");
    printf("   [0] Non, laisser à l'origine (0, 0)\n");
    printf("→ Ton choix : ");
    scanf("%d", &placement_ellipse);
    
    if (placement_ellipse == 1) {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│  📐 Configuration de l'ellipse  │\n");
        printf("└─────────────────────────────────┘\n\n");
        
        printf("📍 Centre de l'ellipse :\n");
        printf("   • Coordonnée X : ");
        scanf("%d", &ellipse->x);
        
        printf("   • Coordonnée Y : ");
        scanf("%d", &ellipse->y);
        
        printf("\n📏 Dimensions de l'ellipse :\n");
        printf("   • Rayon horizontal (axe X) : ");
        scanf("%d", &ellipse->rayonx);
        
        printf("   • Rayon vertical (axe Y) : ");
        scanf("%d", &ellipse->rayony);
        
        printf("\n╔════════════════════════════════════╗\n");
        printf("║       ✅ ELLIPSE CRÉÉE !           ║\n");
        printf("╠════════════════════════════════════╣\n");
        printf("║  Centre    :(%d,%d)%-*s║\n", 
               ellipse->x, ellipse->y, 
               18 - (ellipse->x >= 10 ? 1 : 0) - (ellipse->y >= 10 ? 1 : 0), "");
        printf("║  Rayon X   :%d%-*s║\n", 
               ellipse->rayonx, 
               22 - (ellipse->rayonx >= 10 ? 1 : 0), "");
        printf("║  Rayon Y   :%d%-*s║\n", 
               ellipse->rayony, 
               22 - (ellipse->rayony >= 10 ? 1 : 0), "");
        printf("╚════════════════════════════════════╝\n\n");
    } else {
        ellipse->x = 0;
        ellipse->y = 0;
        ellipse->rayonx = 0;
        ellipse->rayony = 0;
        
        printf("\n✅ Ellipse créée à l'origine (0, 0) avec rayons nuls.\n\n");
    }
    
    return ellipse;
}

void free_ellipse(Ellipse* ellipse) {
    free(ellipse);
}