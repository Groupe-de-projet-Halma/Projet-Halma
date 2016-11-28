#ifndef JEU_H
#define JEU_H

#include "utilitaire.h"

typedef struct
{
	int x_debut;
	int x_fin;
	int y_debut;
	int y_fin;
	int modification;
	int incrementation_x;

} Test_fin;	// Contient les variables nécessaire pour la fonction Test_fin


int test_emplacement(int valeur_emplacement, int x, int y, int plateau[][TAILLE_PLATEAU]);   // Test la valeur de l'emplacement du plateau
void selection_coordonne(int tableau_coord[]);	// Demande les valeurs et remplis le tableau [X;Y]
int deplacer_pion(DonneesPartie *variable_partie);	// Permet le déplacement d'un pion
int joueur_suivant(int nombre_joueur, int numero_joueur, int classement[]);	// Retourne le numero du joueur suivant (MIN = 1 & MAX = 4)
int demande_fin_tour();	// Demmande au joueur si il a fini son tour
void generation_classement(DonneesPartie *variable_partie);	// Remplis le tableau du classement
int somme_classement(DonneesPartie *variable_partie);	// Fait la somme des valeurs de toutes les cases du tableau classement
void fin_joueur(Test_fin *fin, DonneesPartie *variable_partie);	// Test si le joueur x a fini

#endif
