//
// Created by Aurelien on 11/2/2022.
//

#ifndef PROJET_GENERATEUR_TXT_FONCTIONS_H
#define PROJET_GENERATEUR_TXT_FONCTIONS_H

#define ALPHABET 28

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree_verbe.h"
#include "tree_nom.h"
#include "tree_adject.h"


int convertCharInInt(char letter);

void generateBaseSentenceModel1(FILE* filename);
void generateBaseSentenceModel2(FILE* filename);

#endif //PROJET_GENERATEUR_TXT_FONCTIONS_H
