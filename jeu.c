#include "jeu.h"

int test_emplacement(int valeur_emplacement, int x, int y, const int plateau[][TAILLE_PLATEAU])
{
    if (((x >= 0 && x < TAILLE_PLATEAU) && (y >= 0 && y < TAILLE_PLATEAU)) && plateau[x][y] == valeur_emplacement)
        return 1;
    else return 0;
}

void selection_coordonne(int tableau_coord[2])
{
    do
    {
        printf("Entrez coordonnee X: ");
        if(scanf("%d",&tableau_coord[0]) != 1)
            vider_buffer();
    } while (tableau_coord[0] < 0 || tableau_coord[0] >= TAILLE_PLATEAU);

    do
    {
        printf("Entrez coordonnee Y: ");
        if(scanf("%d",&tableau_coord[1]) != 1)
            vider_buffer();
    } while (tableau_coord[1] < 0 || tableau_coord[1] >= TAILLE_PLATEAU);
}

int deplacer_pion(DonneesPartie *variable_partie)
{
    int ecart_x = variable_partie->coord_destination_pion[0] - variable_partie->coord_pion_selectionner[0];
    int ecart_y = variable_partie->coord_destination_pion[1] - variable_partie->coord_pion_selectionner[1];

    if (ecart_x == 0 && ecart_y == 0)
        return 0;

    if (test_emplacement(variable_partie->num_joueur,
                         variable_partie->coord_pion_selectionner[0],
                         variable_partie->coord_pion_selectionner[1],
                         variable_partie->plateau) == 0)
        return 0;

    if ( (ecart_x < 2 && ecart_y < 2) && (ecart_x > -2 && ecart_y > -2))
    {
        if (variable_partie->pion_sauter == 0)
        {
            printf("Deplacer sans sauter de pion\n");

            if(test_emplacement(0,
                                variable_partie->coord_destination_pion[0],
                                variable_partie->coord_destination_pion[1],
                                variable_partie->plateau) == 1)
            {
                variable_partie->plateau[variable_partie->coord_destination_pion[0]][variable_partie->coord_destination_pion[1]] = variable_partie->num_joueur;
                variable_partie->plateau[variable_partie->coord_pion_selectionner[0]][variable_partie->coord_pion_selectionner[1]] = 0;
                return 1; // Deplacement d'une case
            }
        }
    }

    // Deplacement sauter pion
    else if ( ((ecart_x < 3 && ecart_y < 3) && (ecart_x > -3 && ecart_y > -3)) && ((ecart_x != 1 && ecart_x != -1) && (ecart_y != 1 && ecart_y != -1)))
    {
        // Calcul coordonne obstacle
        if (ecart_x > 0)
            ecart_x = ecart_x - 1;
        else if (ecart_x < 0)
            ecart_x = ecart_x + 1;

        if (ecart_y > 0)
            ecart_y = ecart_y - 1;
        else if (ecart_y < 0)
            ecart_y = ecart_y + 1;

        if (test_emplacement(0,
                             variable_partie->coord_pion_selectionner[0] + ecart_x,
                             variable_partie->coord_pion_selectionner[1] + ecart_y,
                             variable_partie->plateau) == 0
            &&
            test_emplacement(0,
                             variable_partie->coord_destination_pion[0],
                             variable_partie->coord_destination_pion[1],
                             variable_partie->plateau) == 1)
        {
            variable_partie->plateau[variable_partie->coord_destination_pion[0]][variable_partie->coord_destination_pion[1]] = variable_partie->num_joueur;
            variable_partie->plateau[variable_partie->coord_pion_selectionner[0]][variable_partie->coord_pion_selectionner[1]] = 0;
            variable_partie->coord_pion_selectionner[0] = variable_partie->coord_destination_pion[0];
            variable_partie->coord_pion_selectionner[1] = variable_partie->coord_destination_pion[1];
            variable_partie->pion_sauter = 1;
            return 2; // Deplacement de 2 case en sautant un pion
        }

    }
    return 0; // Deplacement impossible
}

int joueur_suivant(const int nombre_joueur, int numero_joueur, const int classement[])
{
    int i,j,cpt = 0,fini = 0;
    numero_joueur++;
    if (numero_joueur > nombre_joueur)
        numero_joueur = numero_joueur - nombre_joueur;

    for (i = 0; i < nombre_joueur ; i++)
    {
        cpt = numero_joueur + i;
        if (cpt > nombre_joueur)
            cpt = cpt - nombre_joueur;

        for (j = 0; j < nombre_joueur; j++)
        {
            if (classement[j] == cpt)
                fini = 1;
        }
        if(fini == 0)
            return cpt;
        else fini = 0;
    }

    return 0;
}

int demande_fin_tour()
{
    int continuer;
    do
    {
        printf("Voulez-vous mettre fin a votre tour ? (1 = oui et 0 = non): ");
        if(scanf("%d", &continuer) != 1) // Test si la valeur est un entier
            vider_buffer();

    } while (continuer != 0  && continuer != 1); // Test si l'entre est valide
    return continuer;
}
