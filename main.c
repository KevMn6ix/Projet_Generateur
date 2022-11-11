#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "txt_fonctions.h"
#include "tree_verbe.h"
#include "tree_nom.h"
#include "tree_adject.h"




int main()
{
    srand(time(NULL));

    generateBaseSentenceModel1("C:\\Users\\PC-Aurelien\\Desktop\\Projet_Generateur_Copy_version\\dictionnaire_non_accentue.txt");
    printf("\n");
    generateBaseSentenceModel2("C:\\Users\\PC-Aurelien\\Desktop\\Projet_Generateur_Copy_version\\dictionnaire_non_accentue.txt");
    return 0;
}
