//
// Created by kevmu on 28/10/2022.
//

#include "tree_verbe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARKER ')'

tree_vrb creer_arbre_verbe()
{
    FILE *fic ;
    tree_vrb tree;

    fic = fopen("test.txt","r");
    char texte[256];

    while(fgets(texte, 255, fic)!= NULL)
    {
        char ligne[256];
        strcpy(ligne,texte);
        char d[] = "\t";
        char *portion1 = strtok(texte,d);

        char *portion2 = strtok(NULL,d);

        char *portion3 = strtok(NULL,":");


        if(strcmp(portion3,"Ver")==0)
        {
            printf("%s",ligne);

            if(!isVrbInFichier(portion2))
            {

                ajt_vrb_txt(portion2);
            }
        }
    }
    fclose(fic);
    return tree;
}



void ajt_vrb_txt(char* verbe){

    FILE *fic = fopen("verbe.txt", "a+");
    fputs(verbe,fic);
    fputs("\n",fic);
    fclose(fic);
    return;
}

int isVrbInFichier(char* verbe){

    FILE *fic = fopen("verbe.txt", "r");
    char texte[24];
    while(fgets(texte, 23, fic)!= NULL){

        char d[] = "\n";
        char *portion1 = strtok(texte,d);

        if(strcmp(portion1,verbe)==0){
            fclose(fic);
            return 1;
        }
    }
    fclose(fic);
    return 0;
}

noeud_vrb *creerNoeudVerbe(char lettre)
{
    noeud_vrb* new = malloc(sizeof(noeud_vrb));
    new->lettre = lettre;
    for(int i = 0; i < ALPHABET; i++)
        new->sons[i] = NULL;
    return new;
}


