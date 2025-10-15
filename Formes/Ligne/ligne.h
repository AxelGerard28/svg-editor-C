#ifndef LIGNE_H
#define LIGNE_H

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

Ligne* create_line(void);
void free_line(Ligne* ligne);

#endif