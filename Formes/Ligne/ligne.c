#include <stdio.h>
#include <stdlib.h>
#include "ligne.h"

Ligne *create_line() {
    Ligne* ligne = malloc(sizeof(Ligne));
    int placement_ligne;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║      ✨  CRÉATION DE LIGNE  ✨     ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📍 Veux-tu placer ta ligne sur le repère ?\n");
    printf("   [1] Oui, je veux choisir les coordonnées\n");
    printf("   [0] Non, laisser à l'origine (0, 0)\n");
    printf("→ Ton choix : ");
    scanf("%d", &placement_ligne);
    
    if (placement_ligne == 1) {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│    📐 Configuration de la ligne │\n");
        printf("└─────────────────────────────────┘\n\n");
        
        printf("📍 Point de départ (P1) :\n");
        printf("   • Coordonnée X1 : ");
        scanf("%d", &ligne->x1);
        
        printf("   • Coordonnée Y1 : ");
        scanf("%d", &ligne->y1);
        
        printf("\n📍 Point d'arrivée (P2) :\n");
        printf("   • Coordonnée X2 : ");
        scanf("%d", &ligne->x2);
        
        printf("   • Coordonnée Y2 : ");
        scanf("%d", &ligne->y2);
        
        printf("\n╔════════════════════════════════════╗\n");
        printf("║         ✅ LIGNE CRÉÉE !           ║\n");
        printf("╠════════════════════════════════════╣\n");
        printf("║  P1 (départ)  :  (%d, %d)%-*s║\n", 
               ligne->x1, ligne->y1, 
               12 - (ligne->x1 >= 10 ? 1 : 0) - (ligne->y1 >= 10 ? 1 : 0), "");
        printf("║  P2 (arrivée) :  (%d, %d)%-*s║\n", 
               ligne->x2, ligne->y2, 
               12 - (ligne->x2 >= 10 ? 1 : 0) - (ligne->y2 >= 10 ? 1 : 0), "");
        printf("╚════════════════════════════════════╝\n\n");
    } else {
        ligne->x1 = 0;
        ligne->y1 = 0;
        ligne->x2 = 0;
        ligne->y2 = 0;
        
        printf("\n✅ Ligne créée de (0, 0) à (0, 0).\n\n");
    }
    
    return ligne;
}

void free_line(Ligne* ligne) {
    free(ligne);
}