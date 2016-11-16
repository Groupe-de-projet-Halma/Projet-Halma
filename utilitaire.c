#include "utilitaire.h"

int choix_nombre_joueur()
{
    int nombre_joueur;
    do
    {
        printf("Entrez le nombre de joueur (2 ou 4): ");
        if(scanf("%d", &nombre_joueur) != 1) // Test si la valeur est un entier
            vider_buffer();

    } while (nombre_joueur != 2  && nombre_joueur != 4); // Test si l'entre est valide
    printf("\nVous avez choisi %d joueurs\n\n", nombre_joueur);
    return nombre_joueur;

}

void vider_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void clear_console()
{
    #ifdef linux    // Si on est sur linux
        system("clear");
    #elif _WIN32    // Sinon si on est sur windows
        system("cls");
    #endif
}

void afficher_plateau(const int plateau[][TAILLE_PLATEAU])
{
    int x,y,i;

    printf(" ###### PLATEAU ######\n\n");
    printf("  ");
    for (i = 0 ; i < TAILLE_PLATEAU ; i++)
    {
        printf(" %d",i);  // affichage coordonnee en abscisse
    }

    printf("\n  ");

    for (i = 0 ; i < TAILLE_PLATEAU ; i++)
    {
        printf(" -");  // decoration
    }

    printf("\n");

    for(y = 0; y < TAILLE_PLATEAU ; y++)
    {
        printf("%d| ",y); // affichage coordonnee en ordonnee
        for(x = 0; x < TAILLE_PLATEAU ; x++)
        {
            printf("%d ",plateau[x][y]); // affichage valeur du tableau
        }
        printf("\n");
    }
    printf("\n");
}

void afficher_classement(const int classement[4],int nombre_joueur)
{
    int i;

    printf(" ##### CLASSEMENT ######\n\n");

    for(i = 0; i<nombre_joueur; i++)
    {
        printf("%d) JOUEUR %d\n",i+1,classement[i]);
    }
    printf("\n");

}

void generation_pions(pions_joueur *pions, int plateau[][TAILLE_PLATEAU])
{
    int x, y;

    for (y = pions->y_debut; y < pions->y_fin; y ++) // y signifit les ordonnées dans notre PLATEAU
    {

        for (x = pions->x_debut; x < pions->x_fin; x++) // x signifit les abscisses dans notre PLATEAU
        {

            plateau [x][y] = pions->numero_joueur; // on change la valeur du PLATEAU
        }

        

        if (pions->modification == 0)			//
							//
            pions->x_fin += pions->incrementation_x;	// on fait différentes incrémentations / décrémentations en fonction du joueur pour placer les pions en pyramide
							//
        else pions->x_debut += pions->incrementation_x;	//
    }
}

void generation_terrain(int nombre_joueur, int plateau[][TAILLE_PLATEAU])
{
    int taille;

    // initialisation d'une variable taille pour savoir la taille de nos pyramides de pions

    if (nombre_joueur == 2)
        taille = 5;
    else taille = 3;

    pions_joueur pions_1 = {    1,		//numéro du joueur
				0, taille,	//données des coordonnées x
				0, taille,	//données des coordonnées y
			     	0, -1		//données nécessaire au if de generation_pions
			    };

    pions_joueur pions_2 = { 	2,						//numéro du joueur
			 	TAILLE_PLATEAU - 1, TAILLE_PLATEAU,		//données des coordonnées x
				TAILLE_PLATEAU - taille, TAILLE_PLATEAU,	//données des coordonnées y
				1, -1						//données nécessaire au if de generation_pions
			     };

    generation_pions(&pions_1, plateau);
    generation_pions(&pions_2, plateau);

    if (nombre_joueur == 4) {

	pions_joueur pions_3 = {	3,						//numéro du joueur
					TAILLE_PLATEAU - taille, TAILLE_PLATEAU,	//données des coordonnées x
					0, taille,					//données des coordonnées y
					1, 1						//données nécessaire au if de generation_pions
				};

	pions_joueur pions_4 = {	4,						//numéro du joueur
					0, 1,						//données des coordonnées x
					TAILLE_PLATEAU - taille, TAILLE_PLATEAU,	//données des coordonnées y
					0, 1						//données nécessaire au if de generation_pions
				
				};

        generation_pions(&pions_3, plateau);
        generation_pions(&pions_4, plateau);
    }
}
