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
    
    printf("Quel numéro de forme veux-tu modifier ? ");
    int index = getint(1, liste->count);
    
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
            shape->formes.carre->x = getint(0, 200);
            printf("y : ");
            shape->formes.carre->y = getint(0, 200);
            printf("longueur : ");
            shape->formes.carre->longueur = getint(0, 200);
            break;
            
        case RECTANGLE:
            printf("Nouvelles coordonnées pour le rectangle:\n");
            printf("x : ");
            shape->formes.rectangle->x = getint(0, 200);
            printf("y : ");
            shape->formes.rectangle->y = getint(0, 200);
            printf("longueur : ");
            shape->formes.rectangle->longueur = getint(0, 200);
            printf("largeur : ");
            shape->formes.rectangle->largeur = getint(0, 200);
            break;
            
        case CERCLE:
            printf("Nouvelles coordonnées pour le cercle:\n");
            printf("x : ");
            shape->formes.cercle->x = getint(0, 200);
            printf("y : ");
            shape->formes.cercle->y = getint(0, 200);
            printf("rayon : ");
            shape->formes.cercle->rayon = getint(0, 200);
            break;
            
        case ELLIPSE:
            printf("Nouvelles coordonnées pour l'ellipse:\n");
            printf("x : ");
            shape->formes.ellipse->x = getint(0, 200);
            printf("y : ");
            shape->formes.ellipse->y = getint(0, 200);
            printf("rayonx : ");
            shape->formes.ellipse->rayonx = getint(0, 200);
            printf("rayony : ");
            shape->formes.ellipse->rayony = getint(0, 200);
            break;
            
        case LIGNE:
            printf("Nouvelles coordonnées pour la ligne:\n");
            printf("x1 : ");
            shape->formes.ligne->x1 = getint(0, 200);
            printf("y1 : ");
            shape->formes.ligne->y1 = getint(0, 200);
            printf("x2 : ");
            shape->formes.ligne->x2 = getint(0, 200);
            printf("y2 : ");
            shape->formes.ligne->y2 = getint(0, 200);
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
    
    printf("Quel numéro de forme veux-tu supprimer ? ");
    int index = getint(1, liste->count);
    
    remove_shape_at(liste, index);
}