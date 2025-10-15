#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int longueur;
} Carre;

typedef struct
{
    int x;
    int y;
    int longueur;
    int largeur;
} Rectangle;

typedef struct
{
    int x;
    int y;
    int rayon;
} Cercle;

typedef struct
{
    int x;
    int y;
    int rayonx;
    int rayony;
} Ellipse;

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Ligne;

typedef enum
{
    CARRE,
    RECTANGLE,
    CERCLE,
    ELLIPSE,
    LIGNE
} TypesFormes;

typedef union
{
    Carre *carre;
    Rectangle *rectangle;
    Cercle *cercle;
    Ligne *ligne;
    Ellipse *ellipse;
} Formes;

typedef struct 
{
    TypesFormes typesformes;
    Formes formes;
}Shape;


#endif