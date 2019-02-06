#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED
#include <stdlib.h>
#include <time.h>//Permet de générer des nombres aléatoires en fonction du temps.

//CONSTANTE
#define INITZERO 0

typedef struct tCellule
{
    int nEtat;//1 = Vivant et 0 = Mort
    int nPreced;// Modifier avec une génération de décalage pour que le jeu de la vie fonctionne correctement.
}tCellule;


//PROTOTYPES
extern void initCellule(tCellule *tCellule);
extern void modifEtatCellule(tCellule *tCellule,const int nNb);
extern void modifPrecedCellule(tCellule *tCellule);


#endif // CELLULE_H_INCLUDED
