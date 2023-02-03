#include "arbres.h"


// Creation Arbre

int max1_s(int a, int b,int c){
	int tmp=a;
	if (b >tmp) tmp = b;
  if (c > tmp) tmp = c;
  return tmp;
}
	
int min1_s(int a, int b,int c){
  	int tmp=a;
	if (b <tmp) tmp = b;
  if (c < tmp) tmp = c;
  return tmp;
		}
int max_s(int a, int b) {
  return (a > b ? a : b);
}
int min_s(int a, int b) {
  return (a < b ? b : a);
}

Arbre_string *CreateArbre_s(char a[30],float b){
    Arbre_string *new2=(Arbre_string *) malloc(sizeof(Arbre_string));
	if(new2==NULL){
		exit(1);
		}
	strcpy(new2->stab,a);
	new2->idd=b;
	new2->fd=NULL;
    new2->fg=NULL;
    new2->equi1=1;
    return new2;
}
// Impression Arbre avec chaine de caractères

void printArbre_s( Arbre_string *a, FILE *output){
	if(a==NULL){
	//printf("\n");
			}
        else{
		printArbre_s(a->fd,output);
		//printf("alt: %d idd: %d",a->val,a->val2);
		fprintf(output,"%s %f\n",a->stab,a->idd);
		printArbre_s(a->fg,output);
		}
		}
