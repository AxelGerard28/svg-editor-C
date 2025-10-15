#include <stdio.h>
#include <stdlib.h>
#include "Formes/structure.h"

#include "Formes/Cercle/cercle.h"
#include "Formes/Rectangle/rectangle.h"
#include "Formes/Carre/carre.h"
#include "Formes/Ellipse/ellipse.h"
#include "Formes/Ligne/ligne.h"
#include "Formes/Enchlignes/enchlignes.h"
#include "Formes/Polygone/polygone.h"
#include "Formes/Trajectoire/trajectoire.h"
#include "Formes/Groupe/groupe.h"
#include "Formes/liste.h"

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



int main(void)
{
    Liste *liste = create_liste();
    int choix;
    
    printf(BLUE "\n╔════════════════════════════════════════╗\n" RESET);
    printf(BLUE "║    Bienvenue dans l'éditeur SVG !     ║\n" RESET);
    printf(BLUE "╚════════════════════════════════════════╝\n" RESET);
    
    while (1) {
        menu_principal();
        scanf("%d", &choix);
        
        switch (choix) {
            case 0:
                printf(YELLOW "\nAu revoir! 👋\n" RESET);
                free_liste(liste);
                return 0;
                
            case 1: {
                Shape *nouvelle_forme = creer_forme();
                if (nouvelle_forme != NULL) {
                    add_shape(liste, nouvelle_forme);
                }
                break;
            }
            
            case 2:
                display_all_shapes(liste);
                break;
                
            case 3:
                modifier_forme(liste);
                break;
                
            case 4:
                supprimer_forme(liste);
                break;
                
            default:
                printf(RED "Choix invalide! Réessaie.\n" RESET);
                break;
        }
    }
    
    return 0;
}


//yokoso watashi no soul soceity