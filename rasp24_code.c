#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
		
		char line[200];
		char *t1, *t2, *t3, *t4, *t5, *t6, *t7 , *t8;

		//Ouvrir fichier eleves.csv
		FILE *eleves=fopen("eleves.csv","r");
		
		//Ouvrir
		FILE *export=fopen("export.sql","w+");
		
		//Suppresion des données existants dans l'export
		freopen("export.sql","w+",export);
		
		int id_promo;
		int id_etat_personne;
				
		while (1)
		{
				fgets(line,200,eleves);
				if (feof(eleves))
					break;
				t1=strtok(line,",");
				t2=strtok(NULL,",");
				t3=strtok(NULL,",");
				t4=strtok(NULL,",");
				t5=strtok(NULL,",");
				t6=strtok(NULL,",");
				t7=strtok(NULL,",");
				t8=strtok(NULL,",");
				
				//Prise en compte des clés privées des autres tables
				if( strcmp (t3,"HF")==0)
					id_promo = 1;
					
				if( strcmp (t3,"II")==0)
					id_promo = 2;	
					
				if( strcmp (t4,"eleve")==0)
					id_etat_personne = 1;
										
				//Ajout de la ligne de commande correspondante dans le fichier sql
				fprintf(export, "INSERT INTO `matos`.`eleve` (`prenom`, `nom`, `tag_nfc`, `email`, `num_tel`, `etat_personne_id`, `promo_id`) VALUES ('%s', '%s', '%s','%s' , '%s',  '%d', '%d');\n" ,  t1, t2, t6, t7, t8, id_etat_personne, id_promo); 
		}
		return 0;	
	}
