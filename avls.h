#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#include "arbres.h"

Arbre_string * Rotation_gauche_s( Arbre_string *a);
Arbre_string * Rotation_droite_s( Arbre_string *a);
Arbre_string * DoubleRotation_gauche_s(Arbre_string *a);
Arbre_string * DoubleRotation_droite_s(Arbre_string *a);
Arbre_string *equiArbre_s(Arbre_string *as);
Arbre_string *insertAVL_sf(Arbre_string *a,char e[30],float v , int *h);
