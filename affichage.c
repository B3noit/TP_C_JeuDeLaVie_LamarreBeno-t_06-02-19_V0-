#include "affichage.h"



 //PROCEDURE accueil//////////////////////////////////////////////////////////////////////////////
 //Description : Affiche un message de bienvenue et éventuellement les règles du jeu.
 //
 //Entrée: Un entier si le joueur veut afficher les règles
 //
 //Sortie: Un message de bienvenue et les règles.
 //
 //Note :
 //////////////////////////////////////////////////////////////////////////////////////////////////////
void accueil()
{
//VAR
int nChoix=INITZERO;

    printf("Bonjour et bienvenue dans le jeu de la vie !\n");
    printf("Connaissez vous les règles de ce jeu ?\n");
    printf("Taper 1 pour affichez les règles.\n");
    scanf("%d",&nChoix);
    if (nChoix==1)
    {
        printf("Le jeu se déroule sur une grille à deux dimensions dont les cases qu’on appelle des « cellules »,\n");
        printf("par analogie avec les cellules vivantes peuvent prendre deux états distincts : « vivante » ou « morte ».\n");
        printf("À chaque étape, l’évolution d’une cellule est entièrement déterminée par l’état de ses huit voisines de la façon suivante :\n");
        printf("Une cellule morte possédant exactement trois voisines vivantes devient vivante elle naît.\n");
        printf("Une cellule vivante possédant deux ou trois voisines vivantes le reste, sinon elle meurt.\n");
    }
    printf("Voilà voilà, amusez vous bien !\n");
}




 //PROCEDURE affichGrille//////////////////////////////////////////////////////////////////////////////
 //Description : Affiche la grille de cellule
 //
 //Entrée: Un tableau de cellule
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
 //Description : Ecrit les détails de chaque génération dans un fichiers texte.
 //
 //Entrée: Un entier(le numero de la generation) et le tableau de cellule.
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
        fprintf(fp,"Durant la génération numéro %d, %d cellules étaient vivantes et %d cellules étaient mortes. \n",nCptGen,nCptVie,nCptMort);
    }
    fclose(fp);
}
