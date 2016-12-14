#ifndef JEU_H
#define JEU_H

#include "utilitaire.h"

int test_emplacement(int valeur_emplacement, int x, int y, int plateau[][TAILLE_PLATEAU]);   // Test la valeur de l'emplacement du plateau
void selection_coordonne(int tableau_coord[]);	// Demande les valeurs et remplis le tableau [X;Y]
int deplacer_pion(DonneesPartie *variable_partie);	// Permet le déplacement d'un pion
int joueur_suivant(int nombre_joueur, int numero_joueur, int classement[]);	// Retourne le numero du joueur suivant (MIN = 1 & MAX = 4)

void generation_classement(DonneesPartie *variable_partie);	// Remplis le tableau du classement
int somme_classement(DonneesPartie *variable_partie);	// Fait la somme des valeurs de toutes les cases du tableau classement
void fin_joueur(Pions_joueur *fin, DonneesPartie *variable_partie);	// Test si le joueur x a fini

void prevision(DonneesPartie *variable_partie);
int recherche_valeur_tableau(int **tableau,int taille, int coord_x, int coord_y);
void recherche_destination( DonneesPartie *variable_partie, int coord_selectionner[2], int deplacement);

#endif
