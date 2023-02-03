#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>


typedef struct Arbre_string
{
    char stab[30];
    float idd;
    struct Arbre_string *fd;
    struct Arbre_string *fg;
    int equi1;
    }Arbre_string;

int max1_s(int a, int b,int c);
int min1_s(int a, int b,int c);
int max_s(int a, int b);
int min_s(int a, int b) ;
Arbre_string *CreateArbre_s(char a[30],float b);
void printArbre_s( Arbre_string *a, FILE *output);
