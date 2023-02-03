# projet-meteo
Pour Compiler

// pour générer les .o -> par exemple gcc -c avl.c
// pour compiler gcc arbres.o abrs.o avls.o arbre.o abr.o avl.o liste_ch.o meteo_projet.c
// pour exécuter localement -> ./a.out nom_fichier.csv option_tri
Sinon via le script
./meteo2601.sh meteo_test.csv -h --option_tri


Pour les options du fichier Shell

argument 1 
-t1 :  produit en sortie le fichier essait1.txt avec en colonnes les numéros de station  puis les températures relevées (en enlevant les doublons) 
-t2 : produit en sortie le fichier essait2.txt avec en colonnes les dates/heures puis les températures 
-p1 :  produit en sortie le fichier essaip1.txt avec en colonnes les numéros de station  puis les pressions relevées (en enlevant les doublons) 
-p2 : produit en sortie le fichier essaip2.txt avec en colonnes les dates/heures puis les pressions 
-h :  produit en sortie le fichier essaih.txt avec en colonnes les numéros de station puis les altitudes (en enlevant les doublons) 
-m : produit en sortie le fichier essaim.txt avec en colonnes les numéros de station puis l'humidité (en enlevant les doublons) 

argument 2
--avl -> exécute l'exécutable ./a.out associé meteo_projet.c avec l'option de tri avl
--abr -> exécute l'exécutable ./a.out associé meteo_projet.c avec l'option de tri abr
--listch -> exécute l'exécutable ./a.out associé meteo_projet.c avec l'option listch
