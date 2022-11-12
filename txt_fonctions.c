//
// Created by Aurelien on 11/2/2022.
//

#include "txt_fonctions.h"

//Cette variable permet de convertir un caractère en son numéro de l'alphabet à la même manière d'un chiffrement de Cesar
int convertCharInInt(char letter)
{
    switch(letter)
    {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        case 'i': return 8;
        case 'j': return 9;
        case 'k': return 10;
        case 'l': return 11;
        case 'm': return 12;
        case 'n': return 13;
        case 'o': return 14;
        case 'p': return 15;
        case 'q': return 16;
        case 'r': return 17;
        case 's': return 18;
        case 't': return 19;
        case 'u': return 20;
        case 'v': return 21;
        case 'w': return 22;
        case 'x': return 23;
        case 'y': return 24;
        case 'z': return 25;
        case '-': return 26;
        case 39 : return 27; //La valeur 29 correspond au code ASCII d'un apostrophe
    }
}

//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - adjectif - verbe - nom
void generateBaseSentenceModel1(FILE* filename)
{
    t_tree_nom noms = generateTreeNom(filename); //On génère l'arbre des noms
    t_tree_adject adjectifs = generateTreeAdject(filename); //On génère l'arbre des adjectifs
    t_tree_vrb verbes = generateTreeVerb(filename); //On génère l'arbre des verbes

    generateNom(noms); //On génère un nom
    generateAdject(adjectifs); //On génère un adjectif
    generateVerb(verbes); //On génère un verbe
    generateNom(noms); //On génère un nom
    printf("\n"); //On retourne à la ligne
}

//Cette fonction permet de générer une phrase de base qui suit le modèle : nom - 'qui' - verbe - verbe - nom - adjectif
void generateBaseSentenceModel2(FILE* filename)
{
    t_tree_nom noms = generateTreeNom(filename); //On génère l'arbre des noms
    t_tree_adject adjectifs = generateTreeAdject(filename); //On génère l'arbre des adjectifs
    t_tree_vrb verbes = generateTreeVerb(filename); //On génère l'arbre des verbes

    generateNom(noms); //On génère un premier nom
    printf("qui "); //On affiche le pronom relatif qui
    generateVerb(verbes);//On génère un premier verbe
    generateVerb(verbes); //On génère un second verbe
    generateNom(noms); //On génère un second nom
    generateAdject(adjectifs); //On génère un adjectif
    printf("\n"); //On retourne à la ligne
}


