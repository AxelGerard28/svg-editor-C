#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "../Shapes/shapes.h"

/**
 * @brief Crée une nouvelle liste chaînée vide
 * 
 * Alloue dynamiquement une nouvelle liste et initialise ses champs.
 * 
 * @return Pointeur vers la nouvelle liste créée
 * 
 * @warning La liste doit être libérée avec free_liste() après utilisation
 */
Liste* create_liste() {
    Liste *liste = malloc(sizeof(Liste));
    liste->head = NULL;
    liste->count = 0;
    return liste;
}

/**
 * @brief Ajoute une forme à la fin de la liste
 * 
 * Crée un nouveau nœud contenant la forme et l'ajoute à la fin
 * de la liste chaînée. Le compteur est automatiquement augmenté de 1.
 * 
 * @param liste Pointeur vers la liste
 * @param shape Pointeur vers la forme à ajouter
 * 
 * @warning liste et shape ne doivent pas être NULL
 */
void add_shape(Liste *liste, Shape *shape) {
    Node *new_node = malloc(sizeof(Node));
    new_node->shape = shape;
    new_node->next = NULL;
    
    if (liste->head == NULL) {
        liste->head = new_node;
    } else {
        Node *current = liste->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    liste->count++;
}

/**
 * @brief Affiche toutes les formes de la liste
 * 
 * Parcourt la liste et affiche les détails de chaque forme
 * (coordonnées, dimensions, couleurs). Gère tous les types de formes :
 * carré, rectangle, cercle, ellipse, ligne et polygone.
 * 
 * @param liste Pointeur vers la liste à afficher
 * 
 * @note Si la liste est vide, affiche un message approprié
 */
void display_all_shapes(Liste *liste) {
    if (liste->head == NULL) {
        printf("\nAucune forme créée pour le moment.\n\n");
        return;
    }
    
    printf("\n========== LISTE DES FORMES ==========\n");
    Node *current = liste->head;
    int index = 1;
    
    while (current != NULL) {
        printf("\nForme %d : ", index);
        
        switch (current->shape->typesformes) {
            case CARRE:
                printf("CARRÉ\n");
                printf("  x = %d, y = %d, longueur = %d\n",
                       current->shape->formes.carre->x,
                       current->shape->formes.carre->y,
                       current->shape->formes.carre->longueur);
                printf("  🎨 Fond: %s | Contour: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_fond,
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;
                
            case RECTANGLE:
                printf("RECTANGLE\n");
                printf("  x = %d, y = %d, longueur = %d, largeur = %d\n",
                       current->shape->formes.rectangle->x,
                       current->shape->formes.rectangle->y,
                       current->shape->formes.rectangle->longueur,
                       current->shape->formes.rectangle->largeur);
                printf("  🎨 Fond: %s | Contour: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_fond,
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;
                
            case CERCLE:
                printf("CERCLE\n");
                printf("  x = %d, y = %d, rayon = %d\n",
                       current->shape->formes.cercle->x,
                       current->shape->formes.cercle->y,
                       current->shape->formes.cercle->rayon);
                printf("  🎨 Fond: %s | Contour: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_fond,
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;
                
            case ELLIPSE:
                printf("ELLIPSE\n");
                printf("  x = %d, y = %d, rayonx = %d, rayony = %d\n",
                       current->shape->formes.ellipse->x,
                       current->shape->formes.ellipse->y,
                       current->shape->formes.ellipse->rayonx,
                       current->shape->formes.ellipse->rayony);
                printf("Fond: %s | Contour: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_fond,
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;
                
            case LIGNE:
                printf("LIGNE\n");
                printf("  x1 = %d, y1 = %d, x2 = %d, y2 = %d\n",
                       current->shape->formes.ligne->x1,
                       current->shape->formes.ligne->y1,
                       current->shape->formes.ligne->x2,
                       current->shape->formes.ligne->y2);
                printf("Couleur: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;

            case POLYGONE:  // ← AJOUTER
                printf("POLYGONE\n");
                printf("  Nombre de sommets : %d\n", 
                       current->shape->formes.polygone->nb_points);
                printf("  Points :\n");
                for (int i = 0; i < current->shape->formes.polygone->nb_points; i++) {
                    printf("    P%d: (%d, %d)\n", 
                           i + 1,
                           current->shape->formes.polygone->points[i].x,
                           current->shape->formes.polygone->points[i].y);
                }
                printf("  🎨 Fond: %s | Contour: %s (épaisseur: %d)\n",
                       current->shape->color.couleur_fond,
                       current->shape->color.couleur_contour,
                       current->shape->color.epaisseur_contour);
                break;
        }
        
        current = current->next;
        index++;
    }
    printf("\n======================================\n\n");
}

/**
 * @brief Libère la mémoire allouée pour une forme
 * 
 * Libère la mémoire de la structure spécifique de la forme selon son type,
 * puis libère la structure Shape elle-même.
 * 
 * @param shape Pointeur vers la forme à libérer
 * 
 * @warning shape ne doit pas être NULL
 * 
 * @note Gère automatiquement tous les types de formes
 */
void free_shape(Shape *shape) {
    switch (shape->typesformes) {
        case CARRE:
            free(shape->formes.carre);
            break;
        case RECTANGLE:
            free(shape->formes.rectangle);
            break;
        case CERCLE:
            free(shape->formes.cercle);
            break;
        case ELLIPSE:
            free(shape->formes.ellipse);
            break;
        case LIGNE:
            free(shape->formes.ligne);
            break;
        case POLYGONE:
            free_polygone(shape->formes.polygone);
            break;
    }
    free(shape);
}

/**
 * @brief Récupère une forme à un index donné
 * 
 * Parcourt la liste jusqu'à l'index spécifié et retourne
 * un pointeur vers la forme correspondante.
 * 
 * @param liste Pointeur vers la liste
 * @param index Position de la forme (commence à 1)
 * 
 * @return Pointeur vers la forme trouvée, NULL si index invalide
 * 
 * @warning liste ne doit pas être NULL
 */
Shape* get_shape_at(Liste *liste, int index) {
    if (index < 1 || index > liste->count) {
        return NULL;
    }
    
    Node *current = liste->head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }
    return current->shape;
}

/**
 * @brief Supprime une forme à un index donné
 * 
 * Retire la forme de la liste, libère sa mémoire et met à jour
 * le compteur. Gère correctement la suppression en tête de liste.
 * 
 * @param liste Pointeur vers la liste
 * @param index Position de la forme à supprimer (commence à 1)
 * 
 * @warning liste ne doit pas être NULL
 * 
 * @note Affiche un message d'erreur si l'index est invalide
 */
void remove_shape_at(Liste *liste, int index) {
    if (index < 1 || index > liste->count) {
        printf("Index invalide!\n");
        return;
    }
    
    Node *current = liste->head;
    
    if (index == 1) {
        liste->head = current->next;
        free_shape(current->shape);
        free(current);
    } else {
        Node *prev = NULL;
        for (int i = 1; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free_shape(current->shape);
        free(current);
    }
    
    liste->count--;
    printf("Forme supprimée avec succès!\n");
}

/**
 * @brief Libère toute la mémoire de la liste
 * 
 * Parcourt la liste, libère chaque forme et chaque nœud,
 * puis libère la structure de la liste elle-même.
 * 
 * @param liste Pointeur vers la liste à libérer
 * 
 * @warning Après cet appel, le pointeur liste n'est plus valide
 * 
 * @note Doit être appelée avant la fin du programme pour éviter les fuites mémoire
 */
void free_liste(Liste *liste) {
    Node *current = liste->head;
    while (current != NULL) {
        Node *next = current->next;
        free_shape(current->shape);
        free(current);
        current = next;
    }
    free(liste);
}