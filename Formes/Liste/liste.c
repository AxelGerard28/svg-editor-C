#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Liste* create_liste() {
    Liste *liste = malloc(sizeof(Liste));
    liste->head = NULL;
    liste->count = 0;
    return liste;
}
//ajouter une forme
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
//lister mes formes
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
                break;
                
            case RECTANGLE:
                printf("RECTANGLE\n");
                printf("  x = %d, y = %d, longueur = %d, largeur = %d\n",
                       current->shape->formes.rectangle->x,
                       current->shape->formes.rectangle->y,
                       current->shape->formes.rectangle->longueur,
                       current->shape->formes.rectangle->largeur);
                break;
                
            case CERCLE:
                printf("CERCLE\n");
                printf("  x = %d, y = %d, rayon = %d\n",
                       current->shape->formes.cercle->x,
                       current->shape->formes.cercle->y,
                       current->shape->formes.cercle->rayon);
                break;
                
            case ELLIPSE:
                printf("ELLIPSE\n");
                printf("  x = %d, y = %d, rayonx = %d, rayony = %d\n",
                       current->shape->formes.ellipse->x,
                       current->shape->formes.ellipse->y,
                       current->shape->formes.ellipse->rayonx,
                       current->shape->formes.ellipse->rayony);
                break;
                
            case LIGNE:
                printf("LIGNE\n");
                printf("  x1 = %d, y1 = %d, x2 = %d, y2 = %d\n",
                       current->shape->formes.ligne->x1,
                       current->shape->formes.ligne->y1,
                       current->shape->formes.ligne->x2,
                       current->shape->formes.ligne->y2);
                break;
        }
        
        current = current->next;
        index++;
    }
    printf("\n======================================\n\n");
}

//libérer une forme
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
    }
    free(shape);
}

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