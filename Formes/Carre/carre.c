#include <stdio.h>
#include <stdlib.h>

#include "carre.h"
#include "structure.h"


Carre *create_square() {
    Carre* carre = malloc(sizeof(Carre));
    int placement_carre;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║      ✨  CRÉATION DE CARRÉ  ✨     ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📍 Veux-tu placer ton carré sur le repère ?\n");
    printf("   [1] Oui, je veux choisir les coordonnées\n");
    printf("   [0] Non, laisser à l'origine (0, 0)\n");
    printf("→ Ton choix : ");
    scanf("%d", &placement_carre);
    
    if (placement_carre == 1) {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│    📐 Configuration du carré    │\n");
        printf("└─────────────────────────────────┘\n\n");
        
        printf("📍 Coin supérieur gauche :\n");
        printf("   • Coordonnée X : ");
        scanf("%d", &carre->x);
        
        printf("   • Coordonnée Y : ");
        scanf("%d", &carre->y);
        
        printf("\n📏 Dimension du carré :\n");
        printf("   • Côté : ");
        scanf("%d", &carre->longueur);
        
        printf("\n╔════════════════════════════════════╗\n");
        printf("║         ✅ CARRÉ CRÉÉ !            ║\n");
        printf("╠════════════════════════════════════╣\n");
        printf("║  Position :  (%d, %d)%-*s║\n", 
               carre->x, carre->y, 
               16 - (carre->x >= 10 ? 1 : 0) - (carre->y >= 10 ? 1 : 0), "");
        printf("║  Côté     :  %d%-*s║\n", 
               carre->longueur, 
               21 - (carre->longueur >= 10 ? 1 : 0), "");
        printf("╚════════════════════════════════════╝\n\n");
    } else {
        carre->x = 0;
        carre->y = 0;
        carre->longueur = 0;
        
        printf("\n✅ Carré créé à l'origine (0, 0) avec côté nul.\n\n");
    }
    
    return carre;
}

void free_square(Carre* carre) {
    free(carre);
}