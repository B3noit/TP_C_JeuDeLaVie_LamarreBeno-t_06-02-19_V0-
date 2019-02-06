#include "grille.h"



 //PROCEDURE initGrille//////////////////////////////////////////////////////////////////////////////
 //Description : Permet de parcourir la grille(un tableau de cellules) et d'initialiser chaque cellule.
 //
 //Entrée: Un tableau de cellules.
 //
 //Sortie: Un tableau de cellules dont chacune des cellules est initialisées.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void initGrille(tCellule tGrille [TAILLE][TAILLE])
{
//VAR
int nLig=INITZERO;
int nCol=INITZERO;

    for(nLig=INITZERO;nLig<TAILLE;nLig++)
    {
        for(nCol=INITZERO;nCol<TAILLE;nCol++)
        {
            initCellule(&tGrille[nCol][nLig]);
        }
    }
}



 //PROCEDURE modifEtatGrille//////////////////////////////////////////////////////////////////////////////
 //Description : Permet de parcourir la grille(un tableau de cellules) et de modifier chaque cellule.
 //
 //Entrée: Un tableau de cellules.
 //
 //Sortie: Un tableau de cellules dont les états ont été modifier.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifEtatfGrille(tCellule tGrille [TAILLE][TAILLE])
{
//VAR
int nLig=INITZERO;
int nCol=INITZERO;
int nCptCell=INITZERO;
int nNb=INITZERO;

    for(nLig=INITZERO;nLig<TAILLE;nLig++)
    {
        for(nCol=INITZERO;nCol<TAILLE;nCol++)
        {
            nNb=INITZERO;
            nCptCell=INITZERO;
            nCptCell=nextGen(tGrille,nCol,nLig);
            if (nCptCell==3)
            {
                nNb=1;
            }
            if (nCptCell!=2)
            {
                modifEtatCellule(&tGrille[nCol][nLig],nNb);
            }
        }
    }
}



 //PROCEDURE modifPrecedGrille//////////////////////////////////////////////////////////////////////////////
 //Description : Permet de parcourir la grille(un tableau de cellules) et de modifier chaque cellule.
 //
 //Entrée: Un tableau de cellules.
 //
 //Sortie: Un tableau de cellules dont les états précédents(Preced) ont été modifier.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void modifPrecedGrille(tCellule tGrille [TAILLE][TAILLE])
{
 //VAR
int nLig=INITZERO;
int nCol=INITZERO;

    for(nLig=INITZERO;nLig<TAILLE;nLig++)
    {
        for(nCol=INITZERO;nCol<TAILLE;nCol++)
        {
            modifPrecedCellule(&tGrille[nCol][nLig]);
        }
    }
}




 //FONCTION nextGen//////////////////////////////////////////////////////////////////////////////
 //Description : Cette fonction analyse les états précédents des cellules autour d'une cellule et les comptes.
 //
 //Entrée: Un tableau de cellules.
 //
 //Sortie: Un entier.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
int nextGen(tCellule tGrille [TAILLE][TAILLE],const int nCol,const int nLig)
{
//VAR
int nNbTemp=INITZERO;

    if (nCol!=0 && nCol!=TAILLE && nLig!=0 && nLig!=TAILLE)//Si la cellule ne se trouve pas sur les bords.
    {
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig-UN].nPreced==UN)//verifie la cellule au nord-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig-UN].nPreced==UN)//verifie la case au nord-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
    }

////////CAS PARTICULIERS SUR LES BORDS MAIS PAS DANS LES COINS

    if(nCol==0 && (nLig!=0 && nLig!=TAILLE))//Si la cellule est sur le bord gauche mais pas dans les coins.
    {
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig-UN].nPreced==UN)//verifie la cellule au nord-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
    }



    if(nCol==TAILLE && (nLig!=0 && nLig!=TAILLE))//Si la cellule est sur le bord droit mais pas dans les coins.
    {
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig-UN].nPreced==UN)//verifie la case au nord-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
    }



    if(nLig==0 && (nCol!=0 &&nCol!=TAILLE))//Si la cellule est sur la première la ligne mais pas dans les coins.
    {
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
    }



    if(nLig==TAILLE && (nCol!=0 &&nCol!=TAILLE))//Si la cellule est sur la dernière la ligne mais pas dans les coins.
    {
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig-UN].nPreced==UN)//verifie la case au nord-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig-UN].nPreced==UN)//verifie la cellule au nord-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
    }


////CAS PARTICULIERS : LES COINS DE LA GRILLE

    if(nCol==0 && nLig==0)//Si la cellule est dans le coin nord-ouest de la grille
    {
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
    }


    if(nCol==0 && nLig==TAILLE)//Si la cellule est dans le coin sud-ouest de la grille
    {
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig-UN].nPreced==UN)//verifie la cellule au nord-est
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol+UN][nLig].nPreced==UN)//verifie la cellule à l'est
        {
            nNbTemp=nNbTemp+UN;
        }
    }



    if(nCol==TAILLE && nLig==0)//Si la cellule est dans le coin nord-est de la grille
    {
        if(tGrille[nCol][nLig+UN].nPreced==UN)//verifie la cellule au sud
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig+UN].nPreced==UN)//verifie la cellule au sud-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
    }




    if(nCol==TAILLE && nLig==TAILLE)//Si la cellule est dans le coin sud-est de la grille
    {
        if(tGrille[nCol][nLig-UN].nPreced==UN)//verifie la cellule au nord
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig-UN].nPreced==UN)//verifie la cellule au nord-ouest
        {
            nNbTemp=nNbTemp+UN;
        }
        if(tGrille[nCol-UN][nLig].nPreced==UN)//verifie la case à l'ouest
        {
            nNbTemp=nNbTemp+UN;
        }
    }


    return nNbTemp;
}
