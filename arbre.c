#include "arbre.h"


// Creation Arbre

int max1(int a, int b,int c){
	int tmp=a;
	if (b >tmp) tmp = b;
  if (c > tmp) tmp = c;
  return tmp;
}
	
int min1(int a, int b,int c){
  	int tmp=a;
	if (b <tmp) tmp = b;
  if (c < tmp) tmp = c;
  return tmp;
		}
int max(int a, int b) {
  return (a > b ? a : b);
}
int min(int a, int b) {
  return (a < b ? b : a);
}


Arbre *createArbre( int e, int v){
	Arbre *new1=malloc(sizeof(Arbre));
	if(new1==NULL){
		fprintf(stderr,"Erreur allocation memoire noeud %d\n",e);
		exit(2);
		}
		new1->fg=NULL;
		new1->fd=NULL;
		new1->val=e;
		new1->val2=v;
		new1->equi=1;
		return new1;
}

//Impression Arbre
void printArbre( Arbre *a, FILE *output){
	if(a==NULL){
	printf("\n");
			}
        else{
		printArbre(a->fd,output);
		printf("alt: %d idd: %d",a->val,a->val2);
		fprintf(output,"%d %d\n",a->val,a->val2);
		printArbre(a->fg,output);
		}
		}

