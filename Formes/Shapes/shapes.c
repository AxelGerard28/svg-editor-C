#include <stdlib.h>
#include <stdio.h>

#include "structure.h"
#include "../Create/create.h"

/**
 * @brief Crée un nouveau cercle avec interaction utilisateur
 * 
 * @return Pointeur vers le cercle créé, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
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
/**
 * @brief Libère la mémoire allouée pour un cercle
 * 
 * @param cercle Pointeur vers le cercle à libérer
 * 
 * @return void
 * 
 * @warning cercle ne doit pas être NULL
 */
void free_circle(Cercle* cercle) {
    free(cercle);
}

//ellipse
/**
 * @brief Crée une nouvelle ellipse avec interaction utilisateur
 * 
 * @return Pointeur vers l'ellipse créée, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
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
/**
 * @brief Libère la mémoire allouée pour une ellipse
 * 
 * @param ellipse Pointeur vers l'ellipse à libérer
 * 
 * @return void
 * 
 * @warning ellipse ne doit pas être NULL
 */
void free_ellipse(Ellipse* ellipse){
    free(ellipse);
}


/**
 * @brief Crée un nouveau carre avec interaction utilisateur
 * 
 * @return Pointeur vers le carre créé, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
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
/**
 * @brief Libère la mémoire allouée pour un carre
 * 
 * @param carre Pointeur vers le carre à libérer
 * 
 * @return void
 * 
 * @warning carre ne doit pas être NULL
 */
void free_square(Carre* carre) {
    free(carre);
}


/**
 * @brief Crée un nouveau recatgnle avec interaction utilisateur
 * 
 * @return Pointeur vers le rectangle créé, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
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
/**
 * @brief Libère la mémoire allouée pour un rectangle
 * 
 * @param rectangle Pointeur vers le rectangle à libérer
 * 
 * @return void
 * 
 * @warning rectangle ne doit pas être NULL
 */
void free_rectangle(Rectangle* rectangle) {
    free(rectangle);
}

//ligne
/**
 * @brief Crée une nouvelle ligne avec interaction utilisateur
 * 
 * @return Pointeur vers la ligne créée, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
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
/**
 * @brief Libère la mémoire allouée pour une ligne
 * 
 * @param ligne Pointeur vers la ligne à libérer
 * 
 * @return void
 * 
 * @warning ligne ne doit pas être NULL
 */
void free_line(Ligne* ligne) {
    free(ligne);
}


/**
 * @brief Crée un nouveau polygone avec interaction utilisateur
 * 
 * @return Pointeur vers le polygone créé, ou NULL si annulation
 * 
 * @note Allocation dynamique avec malloc()
 */
Polygone *create_polygone(void) {
    Polygone* polygone = malloc(sizeof(Polygone));
    
    printf("\n+====================================+\n");
    printf("|      CREATION DE POLYGONE          |\n");
    printf("+====================================+\n\n");
    
    printf("Veux-tu creer un polygone ?\n");
    printf("  [1] Oui\n");
    printf("  [0] Non, annuler\n");
    printf("-> Ton choix : ");
    int placement = getint(0, 1);
    
    if (placement == 0) {
        free(polygone);
        printf("\n❌ Creation annulee. Retour au menu.\n\n");
        return NULL;
    }
    
    printf("\n--- Configuration du polygone ---\n\n");
    printf("Combien de sommets pour ton polygone (3-20) ? ");
    polygone->nb_points = getint(3, 20);
    
    polygone->points = malloc(sizeof(Point) * polygone->nb_points);
    
    for (int i = 0; i < polygone->nb_points; i++) {
        printf("\nPoint %d :\n", i + 1);
        printf("  Coordonnee X : ");
        polygone->points[i].x = getint(0, 200);
        
        printf("  Coordonnee Y : ");
        polygone->points[i].y = getint(0, 200);
    }

    printf("\n+====================================+\n");
    printf("|        POLYGONE CREE !             |\n");
    printf("+------------------------------------+\n");
    printf("| Nombre de sommets : %d\n", polygone->nb_points);
    printf("| Points :\n");
    for (int i = 0; i < polygone->nb_points; i++) {
        printf("|   P%d: (%d, %d)\n", i + 1, 
               polygone->points[i].x, 
               polygone->points[i].y);
    }
    printf("+====================================+\n\n");
    
    return polygone;
}

/**
 * @brief Libère la mémoire allouée pour un polygone
 * 
 * @param polygone Pointeur vers le polygone à libérer
 * 
 * @return void
 * 
 * @warning polygone ne doit pas être NULL
 */
void free_polygone(Polygone* polygone) {
    if (polygone != NULL) {
        free(polygone->points);
        free(polygone);
    }
}