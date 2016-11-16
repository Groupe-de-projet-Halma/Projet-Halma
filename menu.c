#include "menu.h"

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