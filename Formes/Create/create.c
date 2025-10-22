#include <stdlib.h>
#include <stdio.h>

#include "../Liste/liste.h"
#include "../structure.h"
#include "../Shapes/shapes.h"

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

void menu_principal() 
{
    printf("\n");
    printf(CYAN "========================================\n" RESET);
    printf(CYAN "        ÉDITEUR SVG - MENU PRINCIPAL    \n" RESET);
    printf(CYAN "========================================\n" RESET);
    printf(GREEN " 1" RESET " - Créer une forme\n");
    printf(GREEN " 2" RESET " - Afficher toutes les formes\n");
    printf(GREEN " 3" RESET " - Modifier une forme\n");
    //printf(GREEN " 4" RESET " - Modifier la couleur d'une forme\n");
    printf(GREEN " 5" RESET " - Supprimer une forme\n");
    printf(RED " 0" RESET " - Quitter\n");
    printf(CYAN "========================================\n" RESET);
    printf("Ton choix : ");
}

void menu_formes()
{
    printf("\n");
    printf(RED "Sélectionne une forme :\n" RESET);
    printf(GREEN " 1" RESET " - Cercle\n");
    printf(GREEN " 2" RESET " - Ellipse\n");
    printf(GREEN " 3" RESET " - Carré\n");
    printf(GREEN " 4" RESET " - Rectangle\n");
    printf(GREEN " 5" RESET " - Ligne\n");
    printf(RED " 0" RESET " - Retour\n");
    printf("Ton choix : ");
}

int getint(int min, int max){
    int choix;
    int resultat;

    while(1){
        resultat = scanf("%d", &choix);

        if (resultat != 1) {
            while (getchar() != '\n');
            printf("Erreur : veuillez entrer un nombre entier.\n");
            printf("Nouvelle tentative : ");
            continue;
        }
        if (choix < min || choix > max) {
            printf("Erreur : la valeur doit être entre %d et %d.\n", min, max);
            printf("Nouvelle tentative : ");
            continue;
        }
        return choix;
    }
}

Shape* creer_forme() {
    menu_formes();
    int choix = getint(0, 5);
    
    Shape *shape = malloc(sizeof(Shape));
    
    switch (choix) {
        case 0:
            free(shape);
            return NULL;
            
        case 1:
            shape->typesformes = CERCLE;
            shape->formes.cercle = create_circle();
            if(shape->formes.cercle == NULL){
                free(shape);
                return NULL;
            }
            break;
            
        case 2:
            shape->typesformes = ELLIPSE;
            shape->formes.ellipse = create_ellipse();
            if(shape->formes.ellipse == NULL){
                free(shape);
                return NULL;
            }
            break;
            
        case 3:
            shape->typesformes = CARRE;
            shape->formes.carre = create_square();
            if(shape->formes.carre == NULL){
                free(shape);
                return NULL;
            }
            break;
            
        case 4:
            shape->typesformes = RECTANGLE;
            shape->formes.rectangle = create_rectangle();
            if(shape->formes.rectangle == NULL){
                free(shape);
                return NULL;
            }
            break;
            
        case 5:
            shape->typesformes = LIGNE;
            shape->formes.ligne = create_line();
            if(shape->formes.ligne == NULL){
                free(shape);
                return NULL;
            }
            break;
            
        default:
            printf("Choix invalide!\n");
            free(shape);
            return NULL;
    }
    
    printf(GREEN "\nForme créée avec succès!\n" RESET);
    return shape;
}

void choose_color(char *couleur_fond, char *couleur_contour, int *epaisseur) {
    printf("\n+====================================+\n");
    printf("|        CHOIX DES COULEURS          |\n");
    printf("+====================================+\n\n");
    
    // Couleur de fond
    printf("Couleur de fond (RGB) :\n");
    printf("  Rouge (0-255) : ");
    int r_fond = getint(0, 255);
    
    printf("  Vert (0-255) : ");
    int g_fond = getint(0, 255);
    
    printf("  Bleu (0-255) : ");
    int b_fond = getint(0, 255);
    
    // Couleur de contour
    printf("\nCouleur de contour (RGB) :\n");
    printf("  Rouge (0-255) : ");
    int r_contour = getint(0, 255);
    
    printf("  Vert (0-255) : ");
    int g_contour = getint(0, 255);
    
    printf("  Bleu (0-255) : ");
    int b_contour = getint(0, 255);
    
    // Épaisseur
    printf("\nEpaisseur du contour (1-10) : ");
    *epaisseur = getint(1, 10);

    sprintf(couleur_fond, "rgb(%d,%d,%d)", r_fond, g_fond, b_fond);
    sprintf(couleur_contour, "rgb(%d,%d,%d)", r_contour, g_contour, b_contour);
    
    printf("\nCouleurs choisies :\n");
    printf("   Fond    : %s\n", couleur_fond);
    printf("   Contour : %s (epaisseur %d)\n\n", couleur_contour, *epaisseur);
}


void modifier_forme(Liste *liste) {
    if (liste->count == 0) {
        printf("\nAucune forme à modifier.\n");
        return;
    }
    
    display_all_shapes(liste);
    
    printf("Quel numéro de forme veux-tu modifier ? ");
    int index = getint(1, liste->count);
    
    Shape *shape = get_shape_at(liste, index);
    if (shape == NULL) {
        printf("Forme inexistante!\n");
        return;
    }
    
    // Menu de modification
    printf("\n+====================================+\n");
    printf("|      QUE VEUX-TU MODIFIER ?        |\n");
    printf("+====================================+\n");
    printf("  [1] Position et dimensions\n");
    printf("  [2] Couleurs\n");
    printf("  [3] Tout modifier\n");
    printf("  [0] Annuler\n");
    printf("-> Ton choix : ");
    int choix_modif = getint(0, 3);
    
    if (choix_modif == 0) {
        printf("\nModification annulée.\n");
        return;
    }
    
    // Modifier la géométrie
    if (choix_modif == 1 || choix_modif == 3) {
        switch (shape->typesformes) {
            case CARRE:
                printf("\n--- Modification du CARRÉ ---\n");
                printf("Nouvelle coordonnée X : ");
                shape->formes.carre->x = getint(0, 200);
                
                printf("Nouvelle coordonnée Y : ");
                shape->formes.carre->y = getint(0, 200);
                
                printf("Nouveau côté : ");
                shape->formes.carre->longueur = getint(1, 200);
                break;
                
            case RECTANGLE:
                printf("\n--- Modification du RECTANGLE ---\n");
                printf("Nouvelle coordonnée X : ");
                shape->formes.rectangle->x = getint(0, 200);
                
                printf("Nouvelle coordonnée Y : ");
                shape->formes.rectangle->y = getint(0, 200);
                
                printf("Nouvelle longueur : ");
                shape->formes.rectangle->longueur = getint(1, 200);
                
                printf("Nouvelle largeur : ");
                shape->formes.rectangle->largeur = getint(1, 200);
                break;
                
            case CERCLE:
                printf("\n--- Modification du CERCLE ---\n");
                printf("Nouvelle coordonnée X : ");
                shape->formes.cercle->x = getint(0, 200);
                
                printf("Nouvelle coordonnée Y : ");
                shape->formes.cercle->y = getint(0, 200);
                
                printf("Nouveau rayon : ");
                shape->formes.cercle->rayon = getint(1, 200);
                break;
                
            case ELLIPSE:
                printf("\n--- Modification de l'ELLIPSE ---\n");
                printf("Nouvelle coordonnée X : ");
                shape->formes.ellipse->x = getint(0, 200);
                
                printf("Nouvelle coordonnée Y : ");
                shape->formes.ellipse->y = getint(0, 200);
                
                printf("Nouveau rayon X : ");
                shape->formes.ellipse->rayonx = getint(1, 200);
                
                printf("Nouveau rayon Y : ");
                shape->formes.ellipse->rayony = getint(1, 200);
                break;
                
            case LIGNE:
                printf("\n--- Modification de la LIGNE ---\n");
                printf("Point de départ (P1) :\n");
                printf("  Nouvelle coordonnée X1 : ");
                shape->formes.ligne->x1 = getint(0, 200);
                
                printf("  Nouvelle coordonnée Y1 : ");
                shape->formes.ligne->y1 = getint(0, 200);
                
                printf("\nPoint d'arrivée (P2) :\n");
                printf("  Nouvelle coordonnée X2 : ");
                shape->formes.ligne->x2 = getint(0, 200);
                
                printf("  Nouvelle coordonnée Y2 : ");
                shape->formes.ligne->y2 = getint(0, 200);
                break;
                
            default:
                printf("Type de forme non supporté.\n");
                return;
        }  
    }
     // Modifier les couleurs
    if (choix_modif == 2 || choix_modif == 3) {
        choose_color(shape->color.couleur_fond, 
                    shape->color.couleur_contour, 
                    &shape->color.epaisseur_contour);
    
    printf("\n✅ Forme modifiée avec succès!\n\n");
    }
}

void supprimer_forme(Liste *liste) {
    if (liste->count == 0) {
        printf("\nAucune forme à supprimer.\n");
        return;
    }
    
    display_all_shapes(liste);
    
    printf("Quel numéro de forme veux-tu supprimer ? ");
    int index = getint(1, liste->count);
    
    remove_shape_at(liste, index);
}


