#include "menu.h"

void clear_console()  // Vide la console
{
    #ifdef linux  // Si on est sur linux
        system("clear");
    #elif _WIN32  // Sinon si on est sur windows
        system("cls");
    #endif
}

int choix_nombre_joueur() // Demande le nombre de joueur
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

void vider_buffer() // Vide le buffer pour le scanf
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void menu ()  // Menu d'acceuil
{
  int choix;

  printf("     ***** HALMA GAME *****\n\nby Tancelin MAZZOTTI & Camille LANGE\n\n");

  printf("************* MENU ***************\n");
  printf("* 1 : Lancer une nouvelle partie *\n");
  printf("* 2 : Charger la dernière partie *\n");
  printf("* 3 : Lire les règles            *\n");
  printf("* 4 : Quitter                    *\n");
  printf("**********************************\n\n");

  do {

    printf("Que choisisez vous ? ");
    if(scanf("%d", &choix) != 1) // Test si la valeur est un entier
        vider_buffer();

  } while(choix != 1 && choix != 2 && choix != 3 && choix != 4);

  /* Test pour savoir ce que l'utilisateur veut faire */

  if (choix == 1) // Lancement d'une nouvelle partie
  {
    lancement_partie();
    recommencer();

  } else if (choix == 2)  // Chargement de la dernière partie jouée
          {
            // Je ne sais pas comment faire le chargement : on ne peut pas utiliser variable_partie car elle n'est pas initialisé.
            //charger(&variable_partie);
            //recommencer();

          } else if (choix == 3)  // Exposé des règles du jeu + demande à l'utilisateur si il veux faire une nouvelle partie ou bien reprendre la dernière partie faite
                  {
                    regles();
                    printf("\nVoulez vous faire une nouvelle partie ou bien reprendre la dernière partie faite ? [0 / 1] ");
                    scanf("%d", &choix);

                    if (choix == 1) // Lancement d'une nouvelle partie
                    {
                      lancement_partie();
                      recommencer();

                    } else if (choix == 2)  // Chargement de la dernière partie jouée
                            {
                              // Je ne sais pas comment faire le chargement : on ne peut pas utiliser variable_partie car elle n'est pas initialisé.
                              //charger(&variable_partie);
                              //recommencer();
                            }

                  } else if (choix == 4)
                          {

                            clear_console();
                          }
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

void recommencer()  // Demande si l'utilisateur veux recommencer le jeu
{
  int recommencer;

  do
  {
      printf("\nVoulez-vous recommencer le jeu ? (1 = oui et 0 = non): ");
      if(scanf("%d", &recommencer) != 1) // Test si la valeur est un entier
          vider_buffer();

  } while (recommencer != 0  && recommencer != 1); // Test si l'entre est valide
}
