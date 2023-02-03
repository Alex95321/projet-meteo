#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include "liste_ch.h"
#include "arbre.h"
#include "arbres.h"

// pour générer les .o -> gcc -c avl.c
// pour compiler gcc arbre.o abr.o avl.o liste_ch.o meteo_projet.c 
// pour exécuter -> ./a.out nom_fichier



typedef struct
{
int num_station;
float temp;
char date[30];
float pression;
int vent;
int alt;
int hum;
} cellule;
		
 int main(int argc, char **argv) 
{
FILE* fichier_tri = NULL; 
FILE *output=NULL; //Fichier de sortie
cellule *tab = NULL;
Chainon *pliste=NULL;
Arbre *parbre=NULL;
Arbre_string *parbre_s=NULL;
Chainon_sf *pliste_s=NULL;
int taille_fich;
int i;
char c;
int cas=0;

int *h=(int *)malloc(sizeof(int));
*h=0;
int *h_s=(int *)malloc(sizeof(int));
*h_s=0;
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
if(strcmp(argv[1],"essaip1.txt")==0)  cas=5;
if(strcmp(argv[1],"essaip2.txt")==0)  cas=6;

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
    if (strcmp(argv[2],"avl")==0) parbre=insertAVL(parbre,tab[i].alt,tab[i].num_station,h);
    else if (strcmp(argv[2],"abr")==0) parbre=InsertABR(parbre,tab[i].alt,tab[i].num_station);
    else if (strcmp(argv[2],"listch")==0) pliste=addUp(pliste,tab[i].alt,tab[i].num_station);
		}
		printf("Affichage final ! et ecriture dans le fichier de sortie");
		output= fopen("Altitude.csv","w"); 
		fprintf(output,"Altitude triées dans l'ordre décroissant pour chaque station \n");
		fprintf(output,"Altitude n°station \n");
    if ((strcmp(argv[2],"avl")==0) || (strcmp(argv[2],"abr")==0))
		printArbre(parbre,output);
    else if (strcmp(argv[2],"listch")==0) printList(pliste,output);
		break;
case 2 :	// humidité
taille_fich=5004;//wc -l essaim.txt -> nb lignes d'un fichier
tab = malloc(taille_fich*sizeof(cellule)); 
int max;
fscanf(fichier_tri,"%d",&tab[0].num_station); 
fscanf(fichier_tri,"%f",&tab[0].hum);
max=tab[0].hum;
for (i=1;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%d",&tab[i].num_station); 
		fscanf(fichier_tri,"%f",&tab[i].hum);
		if (tab[i].num_station==tab[i-1].num_station)
		{
			if (tab[i].hum >max) max=tab[i].hum;
		}
 	          // Tri des max pour chaque station
		else{ 
		// nouvelle station détectée
		if (strcmp(argv[2],"avl")==0) parbre=insertAVL(parbre,max,tab[i-1].num_station,h);
    else if (strcmp(argv[2],"abr")==0) parbre=InsertABR(parbre,max,tab[i-1].num_station);
    else if (strcmp(argv[2],"listch")==0) pliste=addUp(pliste,max,tab[i-1].num_station);
		max=tab[i].hum; // taux d'humidité de la nouvelle station 	
		};
}
		printf("Affichage final ! et ecriture dans le fichier de sortie");
		output= fopen("Humidite.csv","w"); 
		fprintf(output,"humidites max triées dans l'ordre décroissant pour chaque station \n");
		fprintf(output,"humidite n°station \n");
		if ((strcmp(argv[2],"avl")==0) || (strcmp(argv[2],"abr")==0))
		printArbre(parbre,output);
    else if (strcmp(argv[2],"listch")==0) printList(pliste,output);
   break;

case 3 :	//températures 1
taille_fich=22762;//wc -l essait1 -> nb lignes d'un fichier
tab = malloc(taille_fich*sizeof(cellule)); 
float maxi,mini,moy;
int cpt=1;
fscanf(fichier_tri,"%d",&tab[0].num_station); 
fscanf(fichier_tri,"%f",&tab[0].temp);
maxi=tab[0].temp;
mini=tab[0].temp;
moy=tab[0].temp;
output= fopen("temp1.csv","w"); 
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

 case 4 :
 
 taille_fich=2137539; //wc -l essait2.txt -> nb lignes d'un fichier 
 
//taille_fich=88;
 
 tab = malloc(taille_fich*sizeof(cellule));  
 
 cpt=1; 
 
 fscanf(fichier_tri,"%s",tab[0].date);  
 
 fscanf(fichier_tri,"%f",&tab[0].temp); 
 
 moy=tab[0].temp; 
 
 for (i=1;i<taille_fich;i++) 
 
{
 
 fscanf(fichier_tri,"%s",tab[i].date);  
 
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
 if (strcmp(argv[2],"avl")==0) parbre_s=insertAVL_sf(parbre_s,tab[i-1].date,moy,h_s);
    else if (strcmp(argv[2],"abr")==0) parbre_s=InsertABR_s(parbre_s,tab[i-1].date,moy);
    else if (strcmp(argv[2],"listch")==0) pliste_s=addDown_sf(pliste_s,tab[i-1].date,moy); 
 
//printf("i: %d ->%s, %f \n",i,tab[i-1].date,moy);
 
 moy=tab[i].temp; // taux d'humidité de la nouvelle station  
 
};
 
}
 
 printf("Affichage final ! et ecriture dans le fichier de sortie"); 
 
 output= fopen("TempMoy.csv","w");  
 
 fprintf(output,"Temperatures moyennestriées dans l'ordre croissant des dates \n"); 
 
 fprintf(output,"date temp moy \n"); 
 if ((strcmp(argv[2],"avl")==0) || (strcmp(argv[2],"abr")==0))
		printArbre_s(parbre_s,output);
    else if (strcmp(argv[2],"listch")==0) printList_sf(pliste_s,output); 
 break;
case 5 :
taille_fich=30914; //pression 1
tab = malloc(taille_fich*sizeof(cellule)); 
float maxp,minp,moyp;
int cptp=1;
fscanf(fichier_tri,"%d",&tab[0].num_station); 
fscanf(fichier_tri,"%f",&tab[0].pression);
maxp=tab[0].pression;
minp=tab[0].pression;
moyp=tab[0].pression;
output= fopen("pressionp1.csv","w"); 
printf("Prout \n");
fprintf(output,"pressions min,max,moy pour chaque station dans l'ordre croissant du numéro de station\n");
fprintf(output,"n°station / presion min / pression max / moy  \n");

for (i=1;i<taille_fich;i++)
		{
		fscanf(fichier_tri,"%d",&tab[i].num_station); 
		fscanf(fichier_tri,"%f",&tab[i].pression);
		if (tab[i].num_station==tab[i-1].num_station)
		{
			if (tab[i].pression >maxp) maxp=tab[i].pression;
			if (tab[i].pression <minp) minp=tab[i].pression;
			moyp+=tab[i].pression;
			cptp++;
		}
 	          // Tri des max pour chaque station
		else{ 
		// nouvelle station détectée
		moyp=moyp/cptp;
		fprintf(output,"%d %f %f %f \n",tab[i-1].num_station,minp,maxp,moyp);
		maxp=tab[i].pression; // taux d'humidité de la nouvelle station 	
		minp=tab[i].pression;
		moyp=tab[i].pression;
		cpt=1;		
		};
}
   break;
   
case 6 :
 
 taille_fich=2014023; //wc -l essaip2.txt -> nb lignes d'un fichier 
 
//taille_fich=88;
 
 tab = malloc(taille_fich*sizeof(cellule));  
 
 cpt=1; 
 
 fscanf(fichier_tri,"%s",tab[0].date);  
 
 fscanf(fichier_tri,"%f",&tab[0].presion);
); 
 
 moy=tab[0].pression; 
 
 for (i=1;i<taille_fich;i++) 
 
{
 
 fscanf(fichier_tri,"%s",tab[i].date);  
 
 fscanf(fichier_tri,"%f",&tab[i].pression); 
 
 if (strcmp(tab[i].date,tab[i-1].date)==0) 
 {
 
 moy+=tab[i].pression; 
 
 cpt++; 
 
}
 
// Tri des max pour chaque station
 
 else{  
 
// nouvelle station détectée
 
 moy=moy/cpt; 
 if (strcmp(argv[2],"avl")==0) parbre_s=insertAVL_sf(parbre_s,tab[i-1].date,moy,h_s);
    else if (strcmp(argv[2],"abr")==0) parbre_s=InsertABR_s(parbre_s,tab[i-1].date,moy);
    else if (strcmp(argv[2],"listch")==0) pliste_s=addDown_sf(pliste_s,tab[i-1].date,moy); 
 
//printf("i: %d ->%s, %f \n",i,tab[i-1].date,moy);
 
 moy=tab[i].pression; // taux d'humidité de la nouvelle station  
 
};
 
}
 
 printf("Affichage final ! et ecriture dans le fichier de sortie"); 
 
 output= fopen("PressionMoy.csv","w");  
 
 fprintf(output,"Pressions moyennes triées dans l'ordre croissant des dates \n"); 
 
 fprintf(output,"date pression moy \n"); 
 if ((strcmp(argv[2],"avl")==0) || (strcmp(argv[2],"abr")==0))
		printArbre_s(parbre_s,output);
    else if (strcmp(argv[2],"listch")==0) printList_sf(pliste_s,output); 
 break;


default : printf("Ce fichier n'existe pas !");
	break;
};
 fclose(fichier_tri); 

}
