#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

typedef struct Arbre
{
	int val;
	int val2;
	struct Arbre *fd;
	struct Arbre *fg;
	int equi;
	}Arbre;

int max1(int a, int b,int c);
int min1(int a, int b,int c);
int max(int a, int b);
int min(int a, int b) ;
Arbre *createArbre( int e, int v);
void printArbre( Arbre *a, FILE *output);
