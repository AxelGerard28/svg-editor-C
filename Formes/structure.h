#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Structure représentant un carre
 */
typedef struct
{
    int x;
    int y;
    int longueur;
} Carre;

/**
 * @brief Structure représentant un rectangle
 */
typedef struct
{
    int x;
    int y;
    int longueur;
    int largeur;
} Rectangle;

/**
 * @brief Structure représentant un cercle
 */
typedef struct
{
    int x;
    int y;
    int rayon;
} Cercle;

/**
 * @brief Structure représentant une ellipse
 */
typedef struct
{
    int x;
    int y;
    int rayonx;
    int rayony;
} Ellipse;

/**
 * @brief Structure représentant une ligne
 */
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Ligne;

/**
 * @brief Structure représentant un point 2D
 */
typedef struct {
    int x;
    int y;
} Point;

/**
 * @brief Structure représentant un polygone
 */
typedef struct {
    Point *points;
    int nb_points;
} Polygone;

/**
 * @brief enumeration reliant les formes
 */
typedef enum
{
    CARRE,
    RECTANGLE,
    CERCLE,
    ELLIPSE,
    LIGNE,
    POLYGONE
} TypesFormes;

/**
 * @brief union des poiteurs des formes
 */
typedef union
{
    Carre *carre;
    Rectangle *rectangle;
    Cercle *cercle;
    Ligne *ligne;
    Ellipse *ellipse;
    Polygone* polygone;
} Formes;

/**
 * @brief Structure représentant les couleurs et le contour
 */
typedef struct
{
    char couleur_fond[30];
    char couleur_contour[30];
    int epaisseur_contour;
}Color;

/**
 * @brief Structure représentant chaque formes et ses caractéristiques
 */
typedef struct 
{
    TypesFormes typesformes;
    Formes formes;
    Color color;
}Shape;

#endif