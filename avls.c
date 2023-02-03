#include "avls.h"


Arbre_string * Rotation_gauche_s( Arbre_string *a){
	Arbre_string *pivot;
	int eq_1,eq_2;
		pivot=a->fd;
		a->fd=pivot->fg;
		pivot->fg=a;
		eq_1=a->equi1;
		eq_2=pivot->equi1;
		a->equi1= eq_1- max_s(eq_2,0)-1;
		pivot->equi1= min1_s( eq_1-2,eq_1+eq_2-2,eq_2-1);
		a=pivot;
		return a;
		}
Arbre_string * Rotation_droite_s( Arbre_string *a){
	Arbre_string *pivot;
	int eq_1,eq_2;
		pivot=a->fg;
		a->fg=pivot->fd;
		pivot->fd=a;
		eq_1=a->equi1;
		eq_2=pivot->equi1;
		a->equi1= eq_1- min_s(eq_2,0)+1;
		pivot->equi1= max1_s( eq_1+2,eq_1+eq_2+2,eq_2+1);
		a=pivot;
		return a;
		}
Arbre_string * DoubleRotation_gauche_s(Arbre_string *a){
		a->fd=Rotation_droite_s(a->fd);
		return Rotation_gauche_s(a);
		}
Arbre_string * DoubleRotation_droite_s(Arbre_string *a){
		a->fg=Rotation_gauche_s(a->fg);
		return Rotation_droite_s(a);
		}
Arbre_string *equiArbre_s(Arbre_string *as){
	if(as->equi1>=2){
	  if(as->fd->equi1>=0){
		return Rotation_gauche_s(as);
		}
		else{
		return DoubleRotation_gauche_s(as);
			}
			}
		else if(as->equi1 <=-2){
			if(as->fg->equi1<=0){
			return Rotation_droite_s(as);
				}
		else{
			return DoubleRotation_droite_s(as);
		}
		}
		return as;
		}	
Arbre_string *insertAVL_sf(Arbre_string *a,char e[30],float v , int *h){
		if(a==NULL){
            printf("NULL \n");
		*h=1;
		return CreateArbre_s(e,v);
			}
		else if(strcmp(a->stab,e)>=0){
              printf("> \n");
			a->fg=insertAVL_sf(a->fg,e,v,h);
			*h= -*h;
			}
		else if(strcmp(a->stab,e)<0){
              printf("< \n");
			a->fd=insertAVL_sf(a->fd,e,v,h);
			}	
		else{
		     *h=0;
		return a;
			
		}
		if(*h!=0){
            printf("equilibrage \n");
			a->equi1=a->equi1 + *h;
			a=equiArbre_s(a);
			if(a->equi1==0){
                 printf("equilibrage->equi1=0 \n");
				*h=0;
				}
				else{
                      printf("equilibrage->equi1! \n");
				*h=1;
				}
		}
		return a;
	}
	
