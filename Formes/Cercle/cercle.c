#include <stdio.h>
#include <stdlib.h>
#include "cercle.h"

#include "structure.h"


Cercle *create_circle() {
    Cercle* cercle = malloc(sizeof(Cercle));
    int placement_cercle;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║      ✨  CRÉATION DE CERCLE  ✨    ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📍 Veux-tu placer ton cercle sur le repère ?\n");
    printf("   [1] Oui, je veux choisir les coordonnées\n");
    printf("   [0] Non, laisser à l'origine (0, 0)\n");
    printf("→ Ton choix : ");
    scanf("%d", &placement_cercle);
    
    if (placement_cercle == 1) {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│   📐 Configuration du cercle    │\n");
        printf("└─────────────────────────────────┘\n\n");
        
        printf("📍 Centre du cercle :\n");
        printf("   • Coordonnée X : ");
        scanf("%d", &cercle->x);
        
        printf("   • Coordonnée Y : ");
        scanf("%d", &cercle->y);
        
        printf("\n📏 Dimension du cercle :\n");
        printf("   • Rayon : ");
        scanf("%d", &cercle->rayon);
        
        printf("\n╔════════════════════════════════════╗\n");
        printf("║        ✅ CERCLE CRÉÉ !            ║\n");
        printf("╠════════════════════════════════════╣\n");
        printf("║  Centre : (%d, %d)%-*s║\n", 
               cercle->x, cercle->y, 
               19 - (cercle->x >= 10 ? 1 : 0) - (cercle->y >= 10 ? 1 : 0), "");
        printf("║  Rayon  :  %d%-*s║\n", 
               cercle->rayon, 
               23 - (cercle->rayon >= 10 ? 1 : 0), "");
        printf("╚════════════════════════════════════╝\n\n");
    } else {
        cercle->x = 0;
        cercle->y = 0;
        cercle->rayon = 0;
        
        printf("\n✅ Cercle créé à l'origine (0, 0) avec rayon nul.\n\n");
    }
    
    return cercle;
}

void free_circle(Cercle* cercle) {
    free(cercle);
}