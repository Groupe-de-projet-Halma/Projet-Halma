#include "jeu.h"

int test_emplacement(int valeur_emplacement, int x, int y, int plateau[][TAILLE_PLATEAU]) // Test la valeur de l'emplacement du plateau
{
    if (((x >= 0 && x < TAILLE_PLATEAU) && (y >= 0 && y < TAILLE_PLATEAU)) && plateau[x][y] == valeur_emplacement)  // Test si la valeur de la case correspond à la valeur que l'on a passé en parramètre
        return 1;
    else return 0;
}

void selection_coordonne(int tableau_coord[2])  // Demande les valeurs et remplis le tableau [X;Y]
{
    do
    {
        printf("Entrez coordonnee X: ");
        if(scanf("%d",&tableau_coord[0]) != 1) // On demande l'abscisse
            vider_buffer();
    } while (tableau_coord[0] < 0 || tableau_coord[0] >= TAILLE_PLATEAU); // Test si la saisie est correcte sinon on recommence la saisie

    do
    {
        printf("Entrez coordonnee Y: ");
        if(scanf("%d",&tableau_coord[1]) != 1) // On demande l'ordonnée
            vider_buffer();
    } while (tableau_coord[1] < 0 || tableau_coord[1] >= TAILLE_PLATEAU); // Test si la saisie est correcte sinon on recommence la saisie
}

int deplacer_pion(DonneesPartie *variable_partie) // Permet le déplacement d'un pion
{
    int ecart_x = variable_partie->coord_destination_pion[0] - variable_partie->coord_pion_selectionner[0]; // Calcul l'écart en abcisse entre le pion et la destination
    int ecart_y = variable_partie->coord_destination_pion[1] - variable_partie->coord_pion_selectionner[1]; // Calcul l'écart en ordonnée entre le pion et la destination

    if (ecart_x == 0 && ecart_y == 0) // Test si la destination est différente de l'emplacement du pion sélectionné
        return 0;

    if (test_emplacement(variable_partie->num_joueur,
                         variable_partie->coord_pion_selectionner[0],
                         variable_partie->coord_pion_selectionner[1],
                         variable_partie->plateau) == 0)  // Test les coordonnées du pion sélectionné sont valide
        return 0;

    if ( (ecart_x < 2 && ecart_y < 2) && (ecart_x > -2 && ecart_y > -2))  // Test si on veut faire un déplacement sans sauter de pion
    {
        if (variable_partie->pion_sauter == 0)  // Test si l'on avait déjà sauté un pion
        {
            printf("Deplacer sans sauter de pion\n");

            if(test_emplacement(0,
                                variable_partie->coord_destination_pion[0],
                                variable_partie->coord_destination_pion[1],
                                variable_partie->plateau) == 1) // Test si l'emplacement de destination est vide
            {
                variable_partie->plateau[variable_partie->coord_destination_pion[0]][variable_partie->coord_destination_pion[1]] = variable_partie->num_joueur; // Le pion arrive sur la case de destination
                variable_partie->plateau[variable_partie->coord_pion_selectionner[0]][variable_partie->coord_pion_selectionner[1]] = 0; // Libère l'emplacement d'où vient le pion
                return 1; // Deplacement d'une case
            }
        }
    }

    // Deplacement en sautant un pion
    else if ( ((ecart_x < 3 && ecart_y < 3) && (ecart_x > -3 && ecart_y > -3)) && ((ecart_x != 1 && ecart_x != -1) && (ecart_y != 1 && ecart_y != -1))) // Test si l'on se déplace en sautant un pion
    {
        // Calcul des coordonnées de l'obstacle
        if (ecart_x > 0)  // Si l'on va à droite
            ecart_x = ecart_x - 1;
        else if (ecart_x < 0) // Si l'on va à gauche
            ecart_x = ecart_x + 1;

        if (ecart_y > 0)  // Si l'on va en bas
            ecart_y = ecart_y - 1;
        else if (ecart_y < 0)  // Si l'on va en haut
            ecart_y = ecart_y + 1;

        if (test_emplacement(0,
                             variable_partie->coord_pion_selectionner[0] + ecart_x,
                             variable_partie->coord_pion_selectionner[1] + ecart_y,
                             variable_partie->plateau) == 0 // Test si il y a un obstacle
            &&
            test_emplacement(0,
                             variable_partie->coord_destination_pion[0],
                             variable_partie->coord_destination_pion[1],
                             variable_partie->plateau) == 1 // Test si la destination est disponible
            )
        {
            variable_partie->plateau[variable_partie->coord_destination_pion[0]][variable_partie->coord_destination_pion[1]] = variable_partie->num_joueur; // Le pion arrive sur la case de destination
            variable_partie->plateau[variable_partie->coord_pion_selectionner[0]][variable_partie->coord_pion_selectionner[1]] = 0; // Libère l'emplacement d'où vient le pion
            variable_partie->coord_pion_selectionner[0] = variable_partie->coord_destination_pion[0]; // Le pion sélectionné devient le pion sur sa nouvelle case (abscisses)
            variable_partie->coord_pion_selectionner[1] = variable_partie->coord_destination_pion[1]; // Le pion sélectionné devient le pion sur sa nouvelle case (ordonnée)
            variable_partie->pion_sauter = 1; // On a sauté un pion
            return 2; // Deplacement de 2 case en sautant un pion
        }
    }
    return 0; // Deplacement impossible
}

int joueur_suivant(int nombre_joueur, int numero_joueur, int classement[])  // Retourne le numero du joueur suivant (MIN = 1 & MAX = 4)
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

int demande_fin_tour()  // Demmande au joueur si il a fini son tour
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

void generation_classement(DonneesPartie *variable_partie) // Remplis le tableau du classement
{
  int i, total;

  if (variable_partie->nombre_joueur == 2) // La variable total sert à savoir quel joueur on ajoute quand tous les joueurs sauf un ont fini
    total = 3;
    else total = 10;

  for (i = 0; i < variable_partie->nombre_joueur; i++) {
    if (variable_partie->classement[i] == 0)  // Si le tableau ne contient pas de valeur on le remplit avec le numéro du joueur
    {
      variable_partie->classement[i] = variable_partie->num_joueur;

      if (variable_partie->classement[variable_partie->nombre_joueur - 2] != 0) // On regarde si on a mis l'avant dernier joueur dans le tableau pour ajouter le dernier
      {
        variable_partie->classement[variable_partie->nombre_joueur - 1] = total - somme_classement(variable_partie);
      }

    break;
    }
  }
}

int somme_classement(DonneesPartie *variable_partie)  // Fait la somme des valeurs de toutes les cases du tableau classement
{
  int i, somme = 0;

  for (i = 0; i < variable_partie->nombre_joueur - 1; i++) {
    somme += variable_partie->classement[i];
  }

  return somme;
}

void fin_joueur(Pions_joueur *fin, DonneesPartie *variable_partie)  // Test si le joueur x a fini
{
    int x, y, test = 0;

    for (y = fin->y_debut; y < fin->y_fin; y ++) // y signifit les ordonnées dans notre PLATEAU
    {
        for (x = fin->x_debut; x < fin->x_fin; x++) // x signifit les abscisses dans notre PLATEAU
        {
          if (variable_partie->plateau[x][y] != variable_partie->num_joueur) // On test si les pions du joueur sont bien sur les emplacements pour qu'il ait fini
              test ++;
        }

        if (fin->modification == 0)		// On fait différentes incrémentations / décrémentations en fonction du joueur pour tester nos pyramides de pions

            fin->x_fin += fin->incrementation_x;

        else fin->x_debut += fin->incrementation_x;
    }
    printf("%d\n", test);
    if (test == 0) // si test = 0 alors le joueur à fini
      generation_classement(variable_partie);
}
