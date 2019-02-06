#include "cellule.h"



 //PROCEDURE initCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Determine al�atoirement dans quel �tat une cellule est initialis�.
 //
 //Entr�e: Une celllule non initialis�e.
 //
 //Sortie: UNe cellule initialis�e � l'�tat vivant ou mort.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void initCellule(tCellule *tCellule)
{
    tCellule->nEtat= rand()%2;
    tCellule->nPreced = tCellule->nEtat;
}



 //PROCEDURE modifEtatCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Modifie la valeur de l'�tat de la cellule selon un entier re�ue en param�tre.
 //
 //Entr�e: Une cellule.
 //
 //Sortie: Une cellule dont une �ventuelle nouvelle valeur � �t� affect� � l'�tat..
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifEtatCellule(tCellule *tCellule,const int nNb)
{
    tCellule->nEtat = nNb;
}




 //PROCEDURE modifPrecedCellule//////////////////////////////////////////////////////////////////////////////
 //Description : Incremente la valeur de l'�tat de la cellule � l'�tat pr�c�dent de la cellule(Preced).
 //
 //Entr�e: Une cellule avec un �tat et un �tat pr�c�dent(Preced) �ventuellement diff�rent.
 //
 //Sortie: Une cellule avec un �tat et un �tat pr�c�dent(Preced) identique.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifPrecedCellule(tCellule *tCellule)
{
    tCellule->nPreced = tCellule->nEtat;
}
