#include "abrs.h"

Arbre_string* InsertABR_s(Arbre_string *a,char x[30],float v){
		if(a==NULL){
            printf("rpopop");
			return CreateArbre_s(x,v);
				}
			if(strcmp(a->stab,x)>=0){
                printf(" > ");
				a->fg= InsertABR_s(a->fg,x,v);
				}
			else if (strcmp(a->stab,x)<0){
                   printf(" < ");
				a->fd= InsertABR_s(a->fd,x,v);
			}
			 return a;
				
				
}
