#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree_verbe.h"


int main() {

    FILE *fic ;
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
    return 0;
}
