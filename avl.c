#include "avl.h"

Arbre* Rotation_gauche( Arbre *a){
	Arbre *pivot;
	int eq_1,eq_2;
		pivot=a->fd;
		a->fd=pivot->fg;
		pivot->fg=a;
		eq_1=a->equi;
		eq_2=pivot->equi;
		a->equi= eq_1- max(eq_2,0)-1;
		pivot->equi= min1( eq_1-2,eq_1+eq_2-2,eq_2-1);
		a=pivot;
		return a;
		}
Arbre* Rotation_droite( Arbre *a){
	Arbre *pivot;
	int eq_1,eq_2;
		pivot=a->fg;
		a->fg=pivot->fd;
		pivot->fd=a;
		eq_1=a->equi;
		eq_2=pivot->equi;
		a->equi= eq_1- min(eq_2,0)+1;
		pivot->equi= max1( eq_1+2,eq_1+eq_2+2,eq_2+1);
		a=pivot;
		return a;
		}
Arbre* DoubleRotation_gauche(Arbre *a){
		a->fd=Rotation_droite(a->fd);
		return Rotation_gauche(a);
		}
Arbre* DoubleRotation_droite(Arbre *a){
		a->fg=Rotation_gauche(a->fg);
		return Rotation_droite(a);
		}
Arbre *equiArbre(Arbre *a){
	if(a->equi>=2){
	  if(a->fd->equi>=0){
		return Rotation_gauche(a);
		}
		else{
		return DoubleRotation_gauche(a);
			}
			}
		else if(a->equi <=-2){
			if(a->fg->equi<=0){
			return Rotation_droite(a);
				}
		else{
			return DoubleRotation_droite(a);
		}
		}
		return a;
		}
////////////////////////////////////////////////////////////////////
Arbre *insertAVL(Arbre *a,int e, int v, int *h){
		if(a==NULL){		
		*h=1;
		return createArbre(e,v);
			}
		else if(e<=a->val){
			a->fg=insertAVL(a->fg,e,v,h);
			*h= -*h;
			}
		else if(e>a->val){
			a->fd=insertAVL(a->fd,e,v,h);
			}	
		else{
		     *h=0;
		return a;
			
		}
		if(*h!=0){
			a->equi=a->equi + *h;
			a=equiArbre(a);
			if(a->equi==0){
				*h=0;
				}
				else{
				*h=1;
				}
		}
		return a;
	}
