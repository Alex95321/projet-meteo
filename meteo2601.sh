#!/bin/bash 

case $2 in
-t1) echo "produit en sortie les températures min" | cut -f1,11 -d ";"  $1 | sort| uniq | sed -e s/';'/' '/g | awk '{if (NF==2) {print}}' >essait1.txt ;;
-t2) echo "produit en sortie les températures moy globalement" | cut -f2,11 -d ";"  $1 | sort| uniq | sed -e s/';'/' '/g | awk '{if (NF==2) {print}}' >essait2.txt ;;
-t3) echo "produit en sortie les températures par date/heure par station";;
-p1) echo "produit en sortie les pressions min"/ cut -f1,11 -d ";"  $1>essait1.txt ;;
-p2) echo "produit en sortie les pressions moy";;
-p3) echo "produit en sortie les pressions par date/heure par station";;
-h) echo "produit en sortie l'altitude pour chaque station-les altitudes sont triées par ordre décroissant" | cut -f1,14 -d ";" $1 | sort |uniq | sed -e s/';'/' '/g  >essaih.txt ;;
-m) echo "produit en sortie l'humidité max pour chaque station-les valeurs sont triées par ordre décroissant" |cut -f1,6 -d ";" $1 | sort| uniq | sed -e s/';'/' '/g | awk '{if (NF==2) {print}}' >essaim.txt  ;;
--help) echo "Le premier argument...";; 
*) echo "argument 1 invalide-> -t1, 2 ou 3 ou -p1, 2 ou 3 tapez --help pour plus d'explications";;
esac

#for fich in essai*.txt
#do ./projet $fich 
#echo "gnuplot sur le fichier resultant"
#done

#./meteo2601.sh meteo_test.csv -m

#sed '/^\s*$/d'

