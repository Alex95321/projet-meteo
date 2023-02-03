#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

 typedef struct Chainon
{
int elmt;
int elmt2;
struct Chainon *suivant; 
}Chainon;

 typedef struct Chainon_string
{
char elmt[30];
float elmt2;
struct Chainon_string *suivant; 
}Chainon_sf;

Chainon *CreateChainon(int a,int b);
Chainon *InsertBeg(Chainon *pliste, int a, int b);
Chainon *addDown(Chainon *pliste,int a, int b);
Chainon *addUp(Chainon *pliste,int a, int b);
void printList(Chainon *pliste, FILE *output);
Chainon_sf *CreateChainon_sf(char a[30],float b);
Chainon_sf *InsertBeg_sf(Chainon_sf *pliste_s, char a[30], float b);
Chainon_sf *addDown_sf(Chainon_sf *pliste_s,char a[30], float b);
void printList_sf(Chainon_sf *pliste_s, FILE *output);
