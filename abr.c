#include "abr.h"


Arbre* InsertABR(Arbre *a,int x,int v){
		if(a==NULL){
			return createArbre(x,v);
				}
			if(x< a->val || x==a->val){
				a->fg= InsertABR(a->fg,x,v);
				}
			else if (x>a->val){
				a->fd= InsertABR(a->fd,x,v);
			}
			 return a;
				
				
}

