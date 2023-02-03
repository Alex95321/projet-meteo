#include "liste_ch.h"

Chainon *CreateChainon(int a,int b){
    Chainon *c=(Chainon *) malloc(sizeof(Chainon));
	if(c==NULL){
		exit(1);
		}
	c->elmt=a;
	c->elmt2=b;
	c->suivant=NULL;
return c;
}

  
  Chainon *InsertBeg(Chainon *pliste, int a, int b){

		Chainon *new=CreateChainon(a,b);
		new->suivant=pliste;
return new;
}


Chainon *addDown(Chainon *pliste,int a, int b) //tri croissant
{
Chainon *new=CreateChainon(a,b);
Chainon *p1=pliste;
if(pliste==NULL){
pliste=new;
	     }
else if(pliste->elmt > a){
		pliste=InsertBeg(pliste,a,b);
		     }
     else{
	while(p1->suivant!=NULL && p1->suivant->elmt <a )
			{
			p1=p1->suivant;
			};
	if(p1->suivant==NULL)
		{
		 p1->suivant=new;

		}
	else{
	new->suivant=p1->suivant;
	p1->suivant=new;
	    };
        };
 
 return pliste;

}


//////////////////////////////////////////////////////
//Tri décroissant
//////////////////////////////////////////////////////

Chainon *addUp(Chainon *pliste,int a, int b) // Tri decroissant
{
Chainon *new=CreateChainon(a,b);
Chainon *p1=pliste;
if(pliste==NULL){
pliste=new;
	     }
else if(pliste->elmt < a){
		pliste=InsertBeg(pliste,a,b);
		     }
     else{
	while(p1->suivant!=NULL && p1->suivant->elmt >a )
			{
			p1=p1->suivant;
			};
	if(p1->suivant==NULL)
		{
		 p1->suivant=new;

		}
	else{
	new->suivant=p1->suivant;
	p1->suivant=new;
	    };
        };
 
 return pliste;

}

void printList(Chainon *pliste, FILE *output){
Chainon *pt;
pt=(Chainon *) malloc(sizeof(Chainon));
pt=pliste;
if(pt==NULL){
		printf("Liste vide \n");
	  }//pt!=NULL
else{
    while(pt!=NULL){
     //printf("alt : %d idd : %d\n",pt->elmt,pt->elmt2);
     fprintf(output,"%d %d \n",pt->elmt,pt->elmt2);

     pt=pt->suivant;
		};
free(pt);
};
}						




 Chainon_sf *CreateChainon_sf(char a[30],float b){ 
 
 Chainon_sf *c=(Chainon_sf *) malloc(sizeof(Chainon_sf)); 
 
 if(c==NULL){ 
 
 exit(1); 
 
}
 
 strcpy(c->elmt,a); 
 
 c->elmt2=b; 
 
 c->suivant=NULL; 
 
 return c; 
 
}
 
 Chainon_sf *InsertBeg_sf(Chainon_sf *pliste_s, char a[30], float b){ 
 
 Chainon_sf *new=CreateChainon_sf(a,b); 
 
 new->suivant=pliste_s; 
 
 return new; 
 
}
 
 Chainon_sf *addDown_sf(Chainon_sf *pliste_s,char a[30], float b) //tri croissant 
 
{
 
 Chainon_sf *new=CreateChainon_sf(a,b); 
 
 Chainon_sf *p2=pliste_s; 
 
//printf("Hello !\n");
 
 if(pliste_s==NULL){ 
 
 printf("NULL !-> creation cellule\n"); 
 
//pliste_s=new;
 
 return(new); 
 
 //printf("if pliste==NULL -> pliste : %s a : %s\n",pliste_s->elmt,a); 
 
}
 
 else if(strcmp(pliste_s->elmt,a)>0){ 
 
 //printf(" pliste->elmt : %s > a : %s\n",pliste_s->elmt,a); 
 
 new->suivant=pliste_s; 
 
 pliste_s=new; 
 
//printf(" pliste : %s a : %s\n",pliste_s->elmt,a);
 
 printf("> a\n"); 
 
}
 
 else{ 
 
 while(p2->suivant!=NULL && (strcmp(p2->suivant->elmt,a)<0) ) 
 
{
 
 p2=p2->suivant; 
 
//printf("< a\n");
 
};
 
 //printf(" pliste-elemt < a -- pliste->elmt : %s < a : %s\n",pliste_s->elmt,a); 
 
 //printf(" p2 < a -- pliste->elmt : %s < a : %s\n",p2->elmt,a); 
 
 if(p2->suivant==NULL) 
 
{
 
 p2->suivant=new; 
 
}
 
 else{ 
 
 new->suivant=p2->suivant; 
 
 p2->suivant=new; 
 
};
 
};
 
 
 return pliste_s; 
 
}
 
 void printList_sf(Chainon_sf *pliste_s, FILE *output){ 
 
 Chainon_sf *pt; 
 
 pt=(Chainon_sf *) malloc(sizeof(Chainon_sf)); 
 
 pt=pliste_s; 
 
 if(pt==NULL){ 
 
 printf("Liste vide \n"); 
 
 }//pt!=NULL 
 
 else{ 
 
 while(pt!=NULL){ 
 
// printf("alt : %s idd : %f\n",pt->elmt,pt->elmt2);
 
 fprintf(output,"%s %f \n",pt->elmt,pt->elmt2); 
 
 pt=pt->suivant; 
 
};
 
 free(pt); 
 
};
 
} 
 
