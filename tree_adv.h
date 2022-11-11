//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADV_H
#define PROJET_GENERATEUR_TREE_ADV_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

typedef struct fl_adv
{
    int nb_formes;
    char* adv_fl;
}fl_adv;

typedef struct maillon_l_fl_adv
{
    fl_adv value;
    struct maillon_fl_adv *next;
} *p_fl_adv;

typedef struct s_std_list_adv
{
    p_fl_adv head;
} l_fl_adv;

typedef struct s_letter_node_vrb_adv
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    int end_word;
    l_fl_adv adverbes;
    struct noeud_adv* sons[ALPHABET];

}t_letter_node_adv, * p_letter_node_adv;

typedef struct s_tree_adv
{
    p_letter_node_adv root;
}t_tree_adv;

p_letter_node_adv createLetterNodeAdv(char letter);
t_tree_adv createEmptyTreeAdv();

t_tree_adv generateTreeAdv(FILE* filename);

void generateAdv(t_tree_adv tree);

#endif //PROJET_GENERATEUR_TREE_ADV_H
