#ifndef CDATAFRAME_H
#define CDATAFRAME_H

void create_df();
void saisir_entier();

void afficher_df(COLUMN* col, int value);
void afficher_partie_ligne(COLUMN* col, int value);
void afficher_partie_colonne(COLUMN* col, int value);

void ajouter_ligne(COLUMN* col, int value);
void supprimer_lign(COLUMN* col, int value);
void ajouter_colonne(COLUMN* col, int value); 
void supprimer_colonne(COLUMN* col, int value);
void renommer_titre(COLUMN* col, int value);
void chercher_valeur(COLUMN* col, int ligne, int colonne);
void modifier_valeur(COLUMN* col, int ligne, int colonne);
void afficher_titre(COLUMN* col);

void afficher_nb_ligne(COLUMN* col);
void afficher_nb_colonne(COLUMN* col);
void superior_value(COLUMN* col, int value);
void inferior_value(COLUMN* col, int value);
void equal_value(COLUMN* col, int value);

#endif