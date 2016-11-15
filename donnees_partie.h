#ifndef DONNNEES_PARTIE_H
#define DONNNEES_PARTIE_H

#include "utilitaire.h"

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

// fonction de sauvegarde
// fonction chargement

#endif
