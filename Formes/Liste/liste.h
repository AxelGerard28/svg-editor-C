
#ifndef LISTE_H
#define LISTE_H

#include "structure.h"

//noeud de la liste chaînée
typedef struct Node {
    Shape *shape;
    struct Node *next;
} Node;

//liste chaînée
typedef struct {
    Node *head;
    int count;
} Liste;

//fonctions de la liste
Liste* create_liste();

void add_shape(Liste *liste, Shape *shape);

void display_all_shapes(Liste *liste);

Shape* get_shape_at(Liste *liste, int index);

void remove_shape_at(Liste *liste, int index);

void free_liste(Liste *liste);

#endif