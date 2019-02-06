#include "affichage.h"



 //PROCEDURE accueil//////////////////////////////////////////////////////////////////////////////
 //Description : Affiche un message de bienvenue et �ventuellement les r�gles du jeu.
 //
 //Entr�e: Un entier si le joueur veut afficher les r�gles
 //
 //Sortie: Un message de bienvenue et les r�gles.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void accueil()
{
//VAR
int nChoix=INITZERO;

    printf("Bonjour et bienvenue dans le jeu de la vie !\n");
    printf("Connaissez vous les r�gles de ce jeu ?\n");
    printf("Taper 1 pour affichez les r�gles.\n");
    scanf("%d",&nChoix);
    if (nChoix==1)
    {
        printf("Le jeu se d�roule sur une grille � deux dimensions dont les cases qu�on appelle des � cellules �,\n");
        printf("par analogie avec les cellules vivantes peuvent prendre deux �tats distincts : � vivante � ou � morte �.\n");
        printf("� chaque �tape, l��volution d�une cellule est enti�rement d�termin�e par l��tat de ses huit voisines de la fa�on suivante :\n");
        printf("Une cellule morte poss�dant exactement trois voisines vivantes devient vivante elle na�t.\n");
        printf("Une cellule vivante poss�dant deux ou trois voisines vivantes le reste, sinon elle meurt.\n");
    }
    printf("Voil� voil�, amusez vous bien !\n");
}




 //PROCEDURE affichGrille//////////////////////////////////////////////////////////////////////////////
 //Description : Affiche la grille de cellule
 //
 //Entr�e: Un tableau de cellule
 //
 //Sortie: L'affichage du tableau de cellule
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void affichGrille (const tCellule tGrille [TAILLE][TAILLE])
{
//VAR
int nLig=INITZERO;
int nCol=INITZERO;

    for(nLig=INITZERO;nLig<TAILLE;nLig++)
    {
        for(nCol=INITZERO;nCol<TAILLE;nCol++)
        {
            if(tGrille[nCol][nLig].nEtat==1)
            {
                printf("][O");
            }else
            {
                printf("][ ");
            }
        }
        printf("]\n");
    }
}



 //PROCEDURE ecriFichier//////////////////////////////////////////////////////////////////////////////
 //Description : Ecrit les d�tails de chaque g�n�ration dans un fichiers texte.
 //
 //Entr�e: Un entier(le numero de la generation) et le tableau de cellule.
 //
 //Sortie: L'inscription de text dans le fichier text.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void ecriFichier (const tCellule tGrille [TAILLE][TAILLE], const int nCptGen)
{
//VAR
FILE *fp=NULL;
int nLig=INITZERO;
int nCol=INITZERO;
int nCptVie=INITZERO;
int nCptMort=INITZERO;

    for(nLig=INITZERO;nLig<TAILLE;nLig++)
    {
        for(nCol=INITZERO;nCol<TAILLE;nCol++)
        {
            if (tGrille[nCol][nLig].nEtat == 1)
            {
                nCptVie = nCptVie + 1;
            }
            else
            {
                nCptMort = nCptMort + 1;
            }
        }
    }

    if ((fp=fopen("resume_Jeu_de_da_vie.txt","a"))==NULL)
    {
        perror("Erreur de creation de fichier");
    }
    else
    {
        fprintf(fp,"Durant la g�n�ration num�ro %d, %d cellules �taient vivantes et %d cellules �taient mortes. \n",nCptGen,nCptVie,nCptMort);
    }
    fclose(fp);
}
