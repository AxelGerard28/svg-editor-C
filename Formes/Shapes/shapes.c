#include <stdlib.h>
#include <stdio.h>

#include "structure.h"
#include "../Create/create.h"

//cercle

Cercle *create_circle() {
    Cercle* cercle = malloc(sizeof(Cercle));
    
    printf("\n+====================================+\n");
    printf("|       CREATION DE CERCLE           |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu placer ton cercle sur le repere ?\n");
    printf("  [1] Oui, choisir les coordonnees\n");
    printf("  [0] Non, laisser a l'origine\n");
    printf("-> Ton choix : ");
    int placement_cercle = getint(0, 1);
    
    if (placement_cercle == 1) {
        printf("\n--- Configuration du cercle ---\n\n");
        
        printf("Centre du cercle :\n");
        printf("  Coordonnee X : ");
        cercle->x = getint(0, 200);
        
        printf("  Coordonnee Y : ");
        cercle->y = getint(0, 200);
        
        printf("\nDimension :\n");
        printf("  Rayon : ");
        cercle->rayon = getint(0, 200);
        
        printf("\n+====================================+\n");
        printf("|         CERCLE CREE !              |\n");
        printf("+------------------------------------+\n");
        printf("| Centre : (%d, %d)\n", cercle->x, cercle->y);
        printf("| Rayon  : %d\n", cercle->rayon);
        printf("+====================================+\n\n");
    } else {
        free(cercle);
        printf("\nCreation annulee. Retour au menu.\n\n ");
        return NULL;
    }
    
    return cercle;
}

void free_circle(Cercle* cercle) {
    free(cercle);
}

//ellipse

Ellipse *create_ellipse() {
    Ellipse* ellipse = malloc(sizeof(Ellipse));
    
    
    printf("\n+====================================+\n");
    printf("|      CREATION D'ELLIPSE            |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu placer ton ellipse sur le repere ?\n");
    printf("  [1] Oui, choisir les coordonnees\n");
    printf("  [0] Non, laisser a l'origine\n");
    printf("-> Ton choix : ");
    int placement_ellipse = getint(0, 1);

    if (placement_ellipse == 1) {
        printf("\n--- Configuration de l'ellipse ---\n\n");
        
        printf("Centre de l'ellipse :\n");
        printf("  Coordonnee X : ");
        ellipse->x = getint(0, 200);     
        printf("  Coordonnee Y : ");
        ellipse->y = getint(0, 200);
        
        printf("\nDimensions :\n");
        printf("  Rayon horizontal (X) : ");
        ellipse->rayonx = getint(0, 200);
        
        printf("  Rayon vertical (Y) : ");
        ellipse->rayony = getint(0, 200);
        
        printf("\n+====================================+\n");
        printf("|         ELLIPSE CREEE !            |\n");
        printf("+------------------------------------+\n");
        printf("| Centre   : (%d, %d)\n", ellipse->x, ellipse->y);
        printf("| Rayon X  : %d\n", ellipse->rayonx);
        printf("| Rayon Y  : %d\n", ellipse->rayony);
        printf("+====================================+\n\n");
    } else {
        free(ellipse);
        printf("\nCreation annulee. Retour au menu.\n\n");
        return NULL;
    }
    
    return ellipse;
}

void free_ellipse(Ellipse* ellipse){
    free(ellipse);
}

//carre

Carre *create_square() {
    Carre* carre = malloc(sizeof(Carre));
    
    printf("\n+====================================+\n");
    printf("|        CREATION DE CARRE           |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu placer ton carre sur le repere ?\n");
    printf("  [1] Oui, choisir les coordonnees\n");
    printf("  [0] Non, laisser a l'origine\n");
    printf("-> Ton choix : ");
    int placement_carre = getint(0, 1);
    
    if (placement_carre == 1) {
        printf("\n--- Configuration du carre ---\n\n");
        
        printf("Coin superieur gauche :\n");
        printf("  Coordonnee X : ");
        carre->x = getint(0, 200);
        
        printf("  Coordonnee Y : ");
        carre->y = getint(0, 200);
        
        printf("\nDimension :\n");
        printf("  Cote : ");
        carre->longueur = getint(0, 200);
        
        printf("\n+====================================+\n");
        printf("|          CARRE CREE !              |\n");
        printf("+------------------------------------+\n");
        printf("| Position : (%d, %d)\n", carre->x, carre->y);
        printf("| Cote     : %d\n", carre->longueur);
        printf("+====================================+\n\n");
    } else {
        free(carre);
        printf("\nCreation annulee. Retour au menu.\n\n");
        return NULL;
    }
    
    return carre;
}

void free_square(Carre* carre) {
    free(carre);
}

//rectangle

Rectangle *create_rectangle() {
    Rectangle* rectangle = malloc(sizeof(Rectangle));
    
    printf("\n+====================================+\n");
    printf("|      CREATION DE RECTANGLE         |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu placer ton rectangle sur le repere ?\n");
    printf("  [1] Oui, choisir les coordonnees\n");
    printf("  [0] Non, laisser a l'origine\n");
    printf("-> Ton choix : ");
    int placement_rectangle = getint(0, 1);
    
    if (placement_rectangle == 1) {
        printf("\n--- Configuration du rectangle ---\n\n");
        
        printf("Coin superieur gauche :\n");
        printf("  Coordonnee X : ");
        rectangle->x = getint(0, 200);
        
        printf("  Coordonnee Y : ");
        rectangle->y = getint(0, 200);
        
        printf("\nDimensions :\n");
        printf("  Longueur (horizontale) : ");
        rectangle->longueur = getint(0, 200);
        
        printf("  Largeur (verticale) : ");
        rectangle->largeur = getint(0, 200);
        
        printf("\n+====================================+\n");
        printf("|        RECTANGLE CREE !            |\n");
        printf("+------------------------------------+\n");
        printf("| Position : (%d, %d)\n", rectangle->x, rectangle->y);
        printf("| Longueur : %d\n", rectangle->longueur);
        printf("| Largeur  : %d\n", rectangle->largeur);
        printf("+====================================+\n\n");
    } else {
        free(rectangle);
        printf("\nCreation annulee. Retour au menu.\n\n");
        return NULL;
    }
    
    return rectangle;
}

void free_rectangle(Rectangle* rectangle) {
    free(rectangle);
}

//ligne

Ligne *create_line() {
    Ligne* ligne = malloc(sizeof(Ligne));
    
    printf("\n+====================================+\n");
    printf("|        CREATION DE LIGNE           |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu placer ta ligne sur le repere ?\n");
    printf("  [1] Oui, choisir les coordonnees\n");
    printf("  [0] Non, laisser a l'origine\n");
    printf("-> Ton choix : ");
    int placement_ligne = getint(0, 1);
    
    if (placement_ligne == 1) {
        printf("\n--- Configuration de la ligne ---\n\n");
        
        printf("Point de depart (P1) :\n");
        printf("  Coordonnee X1 : ");
        ligne->x1 = getint(0, 200);
        
        printf("  Coordonnee Y1 : ");
        ligne->y1 = getint(0, 200);
        
        printf("\nPoint d'arrivee (P2) :\n");
        printf("  Coordonnee X2 : ");
        ligne->x2 = getint(0, 200);
        
        printf("  Coordonnee Y2 : ");
        ligne->y2 = getint(0, 200);
        
        printf("\n+====================================+\n");
        printf("|          LIGNE CREEE !             |\n");
        printf("+------------------------------------+\n");
        printf("| P1 (depart)  : (%d, %d)\n", ligne->x1, ligne->y1);
        printf("| P2 (arrivee) : (%d, %d)\n", ligne->x2, ligne->y2);
        printf("+====================================+\n\n");
    } else {
        free(ligne);
        printf("\nCreation annulee. Retour au menu.\n\n");
        return NULL;
    }
    
    return ligne;
}

void free_line(Ligne* ligne) {
    free(ligne);
}