#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

Rectangle *create_rectangle() {
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    int placement_rectangle;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║    ✨  CRÉATION DE RECTANGLE  ✨   ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📍 Veux-tu placer ton rectangle sur le repère ?\n");
    printf("   [1] Oui, je veux choisir les coordonnées\n");
    printf("   [0] Non, laisser à l'origine (0, 0)\n");
    printf("→ Ton choix : ");
    scanf("%d", &placement_rectangle);
    
    if (placement_rectangle == 1) {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│  📐 Configuration du rectangle  │\n");
        printf("└─────────────────────────────────┘\n\n");
        
        printf("📍 Coin supérieur gauche :\n");
        printf("   • Coordonnée X : ");
        scanf("%d", &rectangle->x);
        
        printf("   • Coordonnée Y : ");
        scanf("%d", &rectangle->y);
        
        printf("\n📏 Dimensions du rectangle :\n");
        printf("   • Longueur (horizontale) : ");
        scanf("%d", &rectangle->longueur);
        
        printf("   • Largeur (verticale) : ");
        scanf("%d", &rectangle->largeur);
        
        printf("\n╔════════════════════════════════════╗\n");
        printf("║       ✅ RECTANGLE CRÉÉ !          ║\n");
        printf("╠════════════════════════════════════╣\n");
        printf("║  Position :  (%d, %d)%-*s║\n", 
               rectangle->x, rectangle->y, 
               16 - (rectangle->x >= 10 ? 1 : 0) - (rectangle->y >= 10 ? 1 : 0), "");
        printf("║  Longueur :  %d%-*s║\n", 
               rectangle->longueur, 
               21 - (rectangle->longueur >= 10 ? 1 : 0), "");
        printf("║  Largeur  :  %d%-*s║\n", 
               rectangle->largeur, 
               21 - (rectangle->largeur >= 10 ? 1 : 0), "");
        printf("╚════════════════════════════════════╝\n\n");
    } else {
        rectangle->x = 0;
        rectangle->y = 0;
        rectangle->longueur = 0;
        rectangle->largeur = 0;
        
        printf("\n✅ Rectangle créé à l'origine (0, 0) avec dimensions nulles.\n\n");
    }
    
    return rectangle;
}

void free_rectangle(Rectangle* rectangle) {
    free(rectangle);
}