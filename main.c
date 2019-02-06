#include "affichage.h"


int main()
{
    //VAR /Bloc d'initialisation
    FILE *fp=NULL;
    int nContinu = INITZERO;
    int nNbGen = INITZERO;
    tCellule tGrille [TAILLE][TAILLE];

    srand(time(NULL));//Initialisation du g�n�rateur de nombre al�atoire.
    initGrille(tGrille);
    fp=fopen("resume_Jeu_de_da_vie.txt","w");//On �crase un �ventuelle ancien fichier pour en recr�er un fichier vide.



    accueil();

    while (nContinu==0)
    {
        nNbGen = nNbGen + 1;
        affichGrille(tGrille);
        modifEtatfGrille(tGrille);
        modifPrecedGrille(tGrille);
        ecriFichier(tGrille,nNbGen);
        printf("Taper 0 pour passer � la g�n�ration suivante.\n Taper 1 pour quitter.\n");
        scanf("%d",&nContinu);
    }

    fclose(fp);
    printf("Aurevoir !\n");
    return 0;
}
