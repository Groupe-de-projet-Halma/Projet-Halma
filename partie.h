#ifndef PARTIE_H
#define PARTIE_H

#include "utilitaire.h"
#include "donnees_partie.h"
#include "jeu.h"
/*
struct Partie
{
    int num_joueur;
    int nombre_joueur;
    int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
    int classement[4];
    int coord_pion_selectionner[2];
    int coord_destination_pion[2];
    int pion_sauter;
    int resultat_deplacement;
};
*/

int lancement_partie();
int deroulement_tour(DonneesPartie * variable_partie);

#endif
