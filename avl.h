#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#include "arbre.h"

Arbre* Rotation_gauche( Arbre *a);
Arbre* Rotation_droite( Arbre *a);
Arbre* DoubleRotation_gauche(Arbre *a);
Arbre* DoubleRotation_droite(Arbre *a);
Arbre *equiArbre(Arbre *a);
Arbre *insertAVL(Arbre *a,int e, int v, int *h);

