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

// fonction de sauvegarde
void sauvegarde(DonneesPartie * donnes_a_sauvegarder)
{
    FILE * fichier_sauvegarde = NULL;
    fichier_sauvegarde = fopen("partie.save","w");

    if(fichier_sauvegarde != NULL)
    {
        printf("Chargement reussie\n");

        //fputc(int_to_char(0),fichier_sauvegarde);
        for (int y = 0; y < TAILLE_PLATEAU; y++)
        {
        	for (int x = 0; x < TAILLE_PLATEAU; x++)
        	{
        		//fputc(int_to_char(donnes_a_sauvegarder->plateau[x][y]),fichier_sauvegarde);
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

    }
    else printf("Erreur ouverture de fichier sauvegarde\n");


}

// fonction chargement
