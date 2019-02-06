#include "cellule.h"



 //PROCEDURE initCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Determine aléatoirement dans quel état une cellule est initialisé.
 //
 //Entrée: Une celllule non initialisée.
 //
 //Sortie: UNe cellule initialisée à l'état vivant ou mort.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void initCellule(tCellule *tCellule)
{
    tCellule->nEtat= rand()%2;
    tCellule->nPreced = tCellule->nEtat;
}



 //PROCEDURE modifEtatCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Modifie la valeur de l'état de la cellule selon un entier reçue en paramètre.
 //
 //Entrée: Une cellule.
 //
 //Sortie: Une cellule dont une éventuelle nouvelle valeur à été affecté à l'état..
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifEtatCellule(tCellule *tCellule,const int nNb)
{
    tCellule->nEtat = nNb;
}




 //PROCEDURE modifPrecedCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Incremente la valeur de l'état de la cellule à l'état précédent de la cellule(Preced).
 //
 //Entrée: Une cellule avec un état et un état précédent(Preced) éventuellement différent.
 //
 //Sortie: Une cellule avec un état et un état précédent(Preced) identique.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifPrecedCellule(tCellule *tCellule)
{
    tCellule->nPreced = tCellule->nEtat;
}
