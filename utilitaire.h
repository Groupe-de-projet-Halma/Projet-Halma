#ifndef UTILITAIRE_H
#define UTILITAIRE_H

#include <stdio.h>
#include <stdlib.h>
#include "donnees_partie.h"

typedef struct
{
	int numero_joueur;
	int x_debut;
	int x_fin;
	int y_debut;
	int y_fin;
	int modification;
	int incrementation_x;

} pions_joueur;

int choix_nombre_joueur();   // Demande le nombre de joueur
void vider_buffer();         // Vide le buffer pour le scanf
void clear_console();
void afficher_plateau(const int plateau[][TAILLE_PLATEAU]);     // Affiche tout le plateau de jeu
void afficher_classement(const int classement[4], int nombre_joueur);

void generation_terrain(int nombre_joueur,  int plateau[][TAILLE_PLATEAU]);   // Place les pions sur leurs emplacements de départ
void generation_pions(pions_joueur *pions, int plateau[][TAILLE_PLATEAU]);                         // Place les pions du joueur dont on donne le numéro et les coordonnées de ses pions


#endif
