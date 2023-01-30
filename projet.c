
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 


typedef struct
{
int num_station;
float temp;
char date[30];
int pression;
int vent;
int alt;
int hum;
} cellule;

 typedef struct Chainon
{
int elmt;
int elmt2;
struct Chainon *suivant; 
}Chainon;

 typedef struct Chainon_string
{
char elmt[30];
int elmt2;
struct Chainon_string *suivant; 
}Chainon_string;


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

Chainon_string *CreateChainon_s(char a[30],int b){
    Chainon_string *c=(Chainon_string *) malloc(sizeof(Chainon_string));
	if(c==NULL){
		exit(1);
		}
	strcpy(c->elmt,a);
	c->elmt2=b;
	c->suivant=NULL;
return c;
}
  Chainon *InsertBeg(Chainon *pliste, int a, int b){

		Chainon *new=CreateChainon(a,b);
		new->suivant=pliste;
return new;
}
Chainon_string *InsertBeg_s(Chainon_string *pliste, char a[30], int b){

		Chainon_string *new=CreateChainon_s(a,b);
		new->suivant=pliste;
return new;
}


Chainon *addDown(Chainon *pliste,int a, int b) //tri croissant
{
Chainon *new=CreateChainon(a,b);
Chainon *p1=pliste;
printf("Hello !\n");
if(pliste==NULL){
printf("NULL !\n");
pliste=new;
	     }
else if(pliste->elmt > a){
		pliste=InsertBeg(pliste,a,b);
printf("> a\n");
		     }
     else{
	while(p1->suivant!=NULL && p1->suivant->elmt <a )
			{
			p1=p1->suivant;
printf("< a\n");
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



Chainon_string *addDown_s(Chainon_string *pliste,char a[30], int b) //tri croissant
{
Chainon_string *new=CreateChainon_s(a,b);
Chainon_string *p1=pliste;
printf("Hello !\n");
if(pliste==NULL){
printf("NULL !\n");
pliste=new;
	     }
else if(strcmp(pliste->elmt,a)>0){
		pliste=InsertBeg_s(pliste,a,b);
printf("> a\n");
		     }
     else{
	while(p1->suivant!=NULL && strcmp(p1->suivant->elmt,a)<0 )
			{
			p1=p1->suivant;
printf("< a\n");
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
printf("Hello !\n");
if(pliste==NULL){
printf("NULL !\n");
pliste=new;
	     }
else if(pliste->elmt < a){
		pliste=InsertBeg(pliste,a,b);
printf("< a\n");
		     }
     else{
	while(p1->suivant!=NULL && p1->suivant->elmt >a )
			{
			p1=p1->suivant;
printf("< a\n");
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
     printf("alt : %d idd : %d\n",pt->elmt,pt->elmt2);
     fprintf(output,"%d %d \n",pt->elmt,pt->elmt2);

     pt=pt->suivant;
		};
free(pt);
};
}						

void printList_s(Chainon_string *pliste_s, FILE *output){
Chainon_string *pt;
pt=(Chainon_string *) malloc(sizeof(Chainon));
pt=pliste_s;
if(pt==NULL){
		printf("Liste vide \n");
	  }//pt!=NULL
else{
    while(pt!=NULL){
     printf("alt : %s idd : %f\n",pt->elmt,pt->elmt2);
     fprintf(output,"%s %f \n",pt->elmt,pt->elmt2);

     pt=pt->suivant;
		};
free(pt);
};
}	

 int main(int argc, char **argv) 
{
FILE* fichier_tri = NULL; 
FILE *output=NULL; //Fichier de sortie
cellule *tab = NULL;
Chainon *pliste=NULL;
Chainon_string *pliste_s=NULL;
int taille_fich;
int i;
char c;
int cas=0;

printf("Je suis là !\n ");
 // argv[1] vaut t, p, w, h ou m
// argv[2] vaut 0, 1, 2 ou 3
fichier_tri= fopen(argv[1],"r"); 
printf("Je suis là !\n ");
// Tri selon les différents types de fichiers
if(strcmp(argv[1],"essaih.txt")==0)  cas=1;
if(strcmp(argv[1],"essaim.txt")==0)  cas=2;
if(strcmp(argv[1],"essait1.txt")==0)  cas=3;
if(strcmp(argv[1],"essait2.txt")==0)  cas=4;
if(strcmp(argv[1],"essait3.txt")==0)  cas=5;
if(strcmp(argv[1],"essaip.txt")==0)  cas=6;

switch(cas)
//if(strcmp(argv[1],"essaih.txt")==0) Les 2 chaines de caracteres sont identiques strcmp return 0
 { 
 case 1 : //Altitude
	taille_fich=62; // taille fichier après élimination doublon
	tab = malloc(taille_fich*sizeof(cellule)); 
	for (i=0;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%d",&tab[i].num_station); 
		fscanf(fichier_tri,"%d",&tab[i].alt);
		//printf(" it %d, stat : %d, alt : %\n",i,tab[i].num_station,tab[i].alt);
 	          // Tri du tableau
		pliste=addUp(pliste,tab[i].alt,tab[i].num_station);
		}
		printf("Affichage final ! et ecriture dans le fichier de sortie");
		output= fopen("Altitude.txt","w"); 
		fprintf(output,"Altitude triées dans l'ordre décroissant pour chaque station \n");
		fprintf(output,"Altitude n°station \n");
		printList(pliste,output);
		break;
case 2 :	// humidité
taille_fich=5004;//wc -l essaim.txt -> nb lignes d'un fichier
tab = malloc(taille_fich*sizeof(cellule)); 
int max;
fscanf(fichier_tri,"%d",&tab[0].num_station); 
fscanf(fichier_tri,"%d",&tab[0].hum);
max=tab[0].hum;
for (i=1;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%d",&tab[i].num_station); 
		fscanf(fichier_tri,"%d",&tab[i].hum);
		if (tab[i].num_station==tab[i-1].num_station)
		{
			if (tab[i].hum >max) max=tab[i].hum;
		}
 	          // Tri des max pour chaque station
		else{ 
		// nouvelle station détectée
		pliste=addUp(pliste,max,tab[i-1].num_station);
		max=tab[i].hum; // taux d'humidité de la nouvelle station 	
		};
}
		printf("Affichage final ! et ecriture dans le fichier de sortie");
		output= fopen("Humidite.txt","w"); 
		fprintf(output,"humidites max triées dans l'ordre décroissant pour chaque station \n");
		fprintf(output,"humidite n°station \n");
		printList(pliste,output);
   break;

case 3 :	//températures 1
taille_fich=22762;//wc -l essaim.t1 -> nb lignes d'un fichier
tab = malloc(taille_fich*sizeof(cellule)); 
float maxi,mini,moy;
int cpt=1;
fscanf(fichier_tri,"%d",&tab[0].num_station); 
fscanf(fichier_tri,"%f",&tab[0].temp);
maxi=tab[0].temp;
mini=tab[0].temp;
moy=tab[0].temp;
output= fopen("temp1.txt","w"); 
fprintf(output,"températures min,max,moy pour chaque station dans l'ordre croissant du numéro de station\n");
fprintf(output,"n°station / temp min / temp max / moy  \n");

for (i=1;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%d",&tab[i].num_station); 
		fscanf(fichier_tri,"%f",&tab[i].temp);
		if (tab[i].num_station==tab[i-1].num_station)
		{
			if (tab[i].temp >maxi) maxi=tab[i].temp;
			if (tab[i].temp <mini) mini=tab[i].temp;
			moy+=tab[i].temp;
			cpt++;
		}
 	          // Tri des max pour chaque station
		else{ 
		// nouvelle station détectée
		moy=moy/cpt;
		fprintf(output,"%d %f %f %f \n",tab[i-1].num_station,mini,maxi,moy);
		maxi=tab[i].temp; // taux d'humidité de la nouvelle station 	
		mini=tab[i].temp;
		moy=tab[i].temp;
		cpt=1;		
		};
}
   break;

case 4 :	// température 2 à revoir 
taille_fich=1794021;//wc -l essait2.txt -> nb lignes d'un fichier
tab = malloc(taille_fich*sizeof(cellule)); 
cpt=1;
fscanf(fichier_tri,"%s",&tab[0].date); 
fscanf(fichier_tri,"%f",&tab[0].temp);
moy=tab[0].temp;
for (i=1;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%s",&tab[i].date); 
		fscanf(fichier_tri,"%f",&tab[i].temp);
		if (strcmp(tab[i].date,tab[i-1].date)==0)
		{
			moy+=tab[i].temp;
			cpt++;
		}
 	          // Tri des max pour chaque station
		else{ 
		// nouvelle station détectée
		moy=moy/cpt;
		pliste_s=addDown_s(pliste_s,tab[i-1].date,moy);
		moy=tab[i].temp; // taux d'humidité de la nouvelle station 	
		};
}
		printf("Affichage final ! et ecriture dans le fichier de sortie");
		output= fopen("TempMoy.txt","w"); 
		fprintf(output,"Temperatures moyennestriées dans l'ordre croissant des dates \n");
		fprintf(output,"date temp moy \n");
		printList_s(pliste_s,output);
   break;




default : printf("Ce fichier n'existe pas !");
	break;
};
 fclose(fichier_tri); 

}
