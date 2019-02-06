#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED
#include "cellule.h"

//CONST
#define TAILLE 20
#define UN 1

extern void initGrille(tCellule tGrille [TAILLE][TAILLE]);
extern void modifEtatfGrille(tCellule tGrille [TAILLE][TAILLE]);
extern void modifPrecedGrille(tCellule tGrille [TAILLE][TAILLE]);
extern int nextGen(tCellule tGrille [TAILLE][TAILLE],const int nCol, const int nLig);


#endif // GRILLE_H_INCLUDED
