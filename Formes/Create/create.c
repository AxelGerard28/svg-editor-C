#include <stdlib.h>
#include <stdio.h>

#include "../Cercle/cercle.h"
#include "../Rectangle/rectangle.h"
#include "../Carre/carre.h"
#include "../Ellipse/ellipse.h" 
#include "../Ligne/ligne.h"
#include "../liste.h"
#include "../structure.h"

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
    printf(GREEN " 4" RESET " - Supprimer une forme\n");
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

Shape* creer_forme() {
    int choix;
    menu_formes();
    scanf("%d", &choix);
    
    Shape *shape = malloc(sizeof(Shape));
    
    switch (choix) {
        case 0:
            free(shape);
            return NULL;
            
        case 1:
            shape->typesformes = CERCLE;
            shape->formes.cercle = create_circle();
            break;
            
        case 2:
            shape->typesformes = ELLIPSE;
            shape->formes.ellipse = create_ellipse();
            break;
            
        case 3:
            shape->typesformes = CARRE;
            shape->formes.carre = create_square();
            break;
            
        case 4:
            shape->typesformes = RECTANGLE;
            shape->formes.rectangle = create_rectangle();
            break;
            
        case 5:
            shape->typesformes = LIGNE;
            shape->formes.ligne = create_line();
            break;
            
        default:
            printf("Choix invalide!\n");
            free(shape);
            return NULL;
    }
    
    printf(GREEN "\nForme créée avec succès!\n" RESET);
    return shape;
}


void modifier_forme(Liste *liste) {
    if (liste->count == 0) {
        printf("\nAucune forme à modifier.\n");
        return;
    }
    
    display_all_shapes(liste);
    
    int index;
    printf("Quel numéro de forme veux-tu modifier ? ");
    scanf("%d", &index);
    
    Shape *shape = get_shape_at(liste, index);
    if (shape == NULL) {
        printf("Forme inexistante!\n");
        return;
    }
    
    printf("\nModification de la forme %d...\n", index);
    
    switch (shape->typesformes) {
        case CARRE:
            printf("Nouvelles coordonnées pour le carré:\n");
            printf("x : ");
            scanf("%d", &shape->formes.carre->x);
            printf("y : ");
            scanf("%d", &shape->formes.carre->y);
            printf("longueur : ");
            scanf("%d", &shape->formes.carre->longueur);
            break;
            
        case RECTANGLE:
            printf("Nouvelles coordonnées pour le rectangle:\n");
            printf("x : ");
            scanf("%d", &shape->formes.rectangle->x);
            printf("y : ");
            scanf("%d", &shape->formes.rectangle->y);
            printf("longueur : ");
            scanf("%d", &shape->formes.rectangle->longueur);
            printf("largeur : ");
            scanf("%d", &shape->formes.rectangle->largeur);
            break;
            
        case CERCLE:
            printf("Nouvelles coordonnées pour le cercle:\n");
            printf("x : ");
            scanf("%d", &shape->formes.cercle->x);
            printf("y : ");
            scanf("%d", &shape->formes.cercle->y);
            printf("rayon : ");
            scanf("%d", &shape->formes.cercle->rayon);
            break;
            
        case ELLIPSE:
            printf("Nouvelles coordonnées pour l'ellipse:\n");
            printf("x : ");
            scanf("%d", &shape->formes.ellipse->x);
            printf("y : ");
            scanf("%d", &shape->formes.ellipse->y);
            printf("rayonx : ");
            scanf("%d", &shape->formes.ellipse->rayonx);
            printf("rayony : ");
            scanf("%d", &shape->formes.ellipse->rayony);
            break;
            
        case LIGNE:
            printf("Nouvelles coordonnées pour la ligne:\n");
            printf("x1 : ");
            scanf("%d", &shape->formes.ligne->x1);
            printf("y1 : ");
            scanf("%d", &shape->formes.ligne->y1);
            printf("x2 : ");
            scanf("%d", &shape->formes.ligne->x2);
            printf("y2 : ");
            scanf("%d", &shape->formes.ligne->y2);
            break;
    }
    
    printf(GREEN "\nForme modifiée avec succès!\n" RESET);
}

void supprimer_forme(Liste *liste) {
    if (liste->count == 0) {
        printf("\nAucune forme à supprimer.\n");
        return;
    }
    
    display_all_shapes(liste);
    
    int index;
    printf("Quel numéro de forme veux-tu supprimer ? ");
    scanf("%d", &index);
    
    remove_shape_at(liste, index);
}