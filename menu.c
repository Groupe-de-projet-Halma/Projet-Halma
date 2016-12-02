#include "menu.h"

void afficher_menu()  // Affiche le menu
{
  printf("     ***** HALMA GAME *****\n\nby Tancelin MAZZOTTI & Camille LANGE\n\n");

  printf("************* MENU ***************\n");
  printf("* 1 : Lancer une nouvelle partie *\n");
  printf("* 2 : Charger la dernière partie *\n");
  printf("* 3 : Lire les règles            *\n");
  printf("* 4 : Quitter                    *\n");
  printf("**********************************\n\n");
}

void menu ()  // Menu d'acceuil
{
  int choix;

  // Initialisation de la structure nécessaire à notre partie
  DonneesPartie variable_partie = {0,0,{{0}},{0},{0},{0},0,0};

  afficher_menu();

  do {  // Choix sécurisé

    printf("Que choisisez vous ? ");
    if(scanf("%d", &choix) != 1) // Test si la valeur est un entier
        vider_buffer();

  } while(choix != 1 && choix != 2 && choix != 3 && choix != 4);

  /* Test pour savoir ce que l'utilisateur veut faire */

  if (choix == 1) // Lancement d'une nouvelle partie
  {
    variable_partie.nombre_joueur = choix_nombre_joueur();
    generation_terrain(variable_partie.nombre_joueur, variable_partie.plateau);

    lancement_partie(&variable_partie);
    recommencer(&variable_partie);

  }
  else if (choix == 2)  // Chargement de la dernière partie jouée
  {
    charger(&variable_partie);
    lancement_partie(&variable_partie);
    recommencer(&variable_partie);

  }
  else if (choix == 3)  // Exposé des règles du jeu + demande à l'utilisateur si il veux faire une nouvelle partie ou bien reprendre la dernière partie faite
  {
    regles();

    do
    {

      printf("\nVoulez vous faire une nouvelle partie ou bien reprendre la dernière partie faite ? [1 : oui / 0 : non] ");

      if(scanf("%d", &choix) != 1)  // Test si la valeur est un entier
          vider_buffer();

      if (choix == 1) // Lancement d'une nouvelle partie
      {
        variable_partie.nombre_joueur = choix_nombre_joueur();
        generation_terrain(variable_partie.nombre_joueur, variable_partie.plateau);

        lancement_partie(&variable_partie);
        recommencer(&variable_partie);

      }
      else  // Chargement de la dernière partie jouée
      {
        charger(&variable_partie);
        lancement_partie(&variable_partie);
        recommencer(&variable_partie);
      }

     } while (choix != 1 && choix != 0);

  }
  else if (choix == 4)
    clear_console();
}

void regles() // Affiche les règles du jeu
{
  clear_console();

  printf("\n ***** HALMA GAME *****\n\n");
  printf("Le Halma est un jeu de plateau qui peut s'apparenter aux Dames Chinoise classique.\n");
  printf("A un détail près : le plateau est carré, ce qui rend les cases carrées et non hexagonales.\n\n");
  printf("Le but du jeu est donc de déplacer tous ces pions à l'opposé du plateau. De son camp vers le camp du joueur en face.\n\n");
  printf("A chaque tour d'un joueur il peut donc déplacer un de ces pions, 2 types de mouvements sont autorisés : \n");
  printf("- Soit le pion ne se déplace que d'une seule case sans rencontrer d'autres pions.\n");
  printf("- Soit le pion saute un autre pion et donc se déplace de 2 cases.\n\n");
  printf("NOTE : Après s'être déplacé en sautant un pion, le joueur peut (s'il le souhaite) recommencer et sauter un autre pion.\n       Et ainsi de suite jusqu'à ce qu'il ne puisse plus sauter de pions. Mais il n'a pas le droit de faire un déplacement sans sauter de pion.\n\n");
  printf("Le Halma peut se jouer à 2 ou 4 joueurs.\n\n");
  printf("Bonne chance !\n");
}

void recommencer(DonneesPartie *variable_partie)  // Demande si l'utilisateur veux recommencer le jeu
{
  int recommencer;

  do  // Test sécurisé
  {
      printf("\nVoulez-vous recommencer le jeu ? (1 = oui et 0 = non): ");
      if(scanf("%d", &recommencer) != 1) // Test si la valeur est un entier
          vider_buffer();
      if (recommencer == 1) {
        variable_partie->nombre_joueur = choix_nombre_joueur();
        generation_terrain(variable_partie->nombre_joueur, variable_partie->plateau);

        lancement_partie(variable_partie);
      }
  } while (recommencer != 0  && recommencer != 1); // Test si l'entre est valide
}
