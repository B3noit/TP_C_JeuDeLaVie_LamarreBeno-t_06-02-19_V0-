#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <stdio.h> //Pour que le programme reconnaisse le printf


#include "grille.h"


extern void accueil();
extern void affichGrille (const tCellule tGrille [TAILLE][TAILLE]);
extern void ecriFichier (const tCellule tGrille [TAILLE][TAILLE],const int nCptGen);


#endif // AFFICHAGE_H_INCLUDED
