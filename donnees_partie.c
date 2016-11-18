#include "donnees_partie.h"

int char_to_int(char chiffre)
{
	int converstion = chiffre -'0';
	return converstion;
}
char int_to_char(int chiffre)
{
	char converstion = chiffre +'0';
	return converstion;
}


int sauvegarde(DonneesPartie * donnes_a_sauvegarder)
{
    FILE * fichier_sauvegarde = NULL;
    fichier_sauvegarde = fopen("partie.save","w");

    if(fichier_sauvegarde != NULL)
    {
        for (int y = 0; y < TAILLE_PLATEAU; y++)
        {
        	for (int x = 0; x < TAILLE_PLATEAU; x++)
        	{
        		fprintf(fichier_sauvegarde,"%c",int_to_char(donnes_a_sauvegarder->plateau[x][y]));
        	}
            fprintf(fichier_sauvegarde,"\n");
        }

        fprintf(fichier_sauvegarde,"%c\n%c\n",int_to_char(donnes_a_sauvegarder->num_joueur),
        									int_to_char(donnes_a_sauvegarder->nombre_joueur));

        for (int i = 0; i < 4; i++)
        {
        	fprintf(fichier_sauvegarde, "%c",int_to_char(donnes_a_sauvegarder->classement[i]) );
        }

        fclose(fichier_sauvegarde);
        return 1;
    }

    else
    {
        printf("Erreur ouverture de fichier sauvegarde\n");
        return 0;
    }
}

int charger(DonneesPartie * donnes_a_charger)
{
    FILE * fichier_chargement = NULL;
    fichier_chargement = fopen("partie.save","r");
		int x,y,i;
    if (fichier_chargement != NULL)
    {
			for (y = 0; y < TAILLE_PLATEAU; y++)
			{
				for (x = 0; x < TAILLE_PLATEAU; x++)
				{
					donnes_a_charger->plateau[x][y] = char_to_int(fgetc(fichier_chargement)); // chargement plateau
				}
				fgetc(fichier_chargement); // Passage de ligne dans le fichier
			}
			donnes_a_charger->num_joueur = char_to_int(fgetc(fichier_chargement)); // chargement numero de joueur
			fgetc(fichier_chargement); // Passage de ligne dans le fichier
			donnes_a_charger->nombre_joueur = char_to_int(fgetc(fichier_chargement)); //chargement nombre de joueur
			fgetc(fichier_chargement); // Passage de ligne dans le fichier
			for (i = 0; i < 4; i++)
			{
				donnes_a_charger->classement[i] = char_to_int(fgetc(fichier_chargement)); // chargement classement
			}

      fclose(fichier_chargement);
      return 1;
    }

    else
    {
        printf("Erreur ouverture de fichier sauvegarde\n");
        return 0;
    }
}
