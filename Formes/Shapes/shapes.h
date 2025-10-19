#ifndef SHAPES_H
#define SHAPES_H
#include "../structure.h"
#include <stdlib.h>
#include <stdio.h>

//cercle
Cercle* create_circle(void);
void free_square(Carre* carre);

//ellipse
Ellipse* create_ellipse(void);
void free_ellipse(Ellipse* ellipse);

//carre
Carre* create_square(void);
void free_square(Carre* carre);

//rectangle
Rectangle* create_rectangle(void);
void free_rectangle(Rectangle* Rectangle);

//ligne
Ligne* create_line(void);
void free_line(Ligne* ligne);



#endif