#ifndef DONNNEES_PARTIE_H
#define DONNNEES_PARTIE_H

#define TAILLE_PLATEAU 10

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num_joueur;
    int nombre_joueur;
    int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    int classement[4];
    int coord_pion_selectionner[2];
    int coord_destination_pion[2];
    int pion_sauter;
    int resultat_deplacement;
}DonneesPartie;

int char_to_int(char chiffre);
char int_to_char(int chiffre);

int sauvegarde(DonneesPartie * donnes_a_sauvegarder); // sauvegarde la partie
int charger(DonneesPartie * donnees_a_charger); // chargement de la derniere sauvegarde

#endif
