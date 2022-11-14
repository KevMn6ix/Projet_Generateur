//
// Created by Aurelien on 11/14/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADV_H
#define PROJET_GENERATEUR_TREE_ADV_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les noeud de notre arbre des adverbes
typedef struct s_letter_node_adv
{
    char lettre;//On initialise une variable permettant de stocker la lettre de notre noeud
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    struct s_letter_node_adv* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_adv, *p_letter_node_adv;

//On définit une structure qui va correspondre à notre arbre d'adverbes
typedef struct s_tree_adv
{
    p_letter_node_adv root;
}t_tree_adv;

//Cette fonction permet de créer un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_adv createLetterNodeAdv(char letter);

//Cette fonction permet de créer un arbre d'adverbes vide
t_tree_adv createEmptyTreeAdv();

//Cette fonction permet de générer un arbre d'adverbes l'aide d'un dictionnaire
t_tree_adv generateTreeAdv(FILE* filename);

//Cette fonction permet de générer un adverbe à partir d'un arbre d'adverbes
void generateAdv(t_tree_adv tree);

#endif //PROJET_GENERATEUR_TREE_ADV_H

