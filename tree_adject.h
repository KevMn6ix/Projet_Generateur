//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADJECT_H
#define PROJET_GENERATEUR_TREE_ADJECT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

typedef struct fl_adject
{
    int nb_formes; // Nombre de formes flechies
    char* adj_fl;
    char genre[3]; // Masculin/feminin
    char nombre_gr[2]; //Nombre grammatical : singulier/ pluriel
}fl_adject;


typedef struct maillon_l_fl_adject
{
    fl_adject value;
    struct maillon_fl_adj *next;
} *p_fl_adject;

typedef struct s_std_list_adject
{
    p_fl_adject head;
} l_fl_adject;

typedef struct s_letter_node_vrb_adject
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    int end_word;
    l_fl_adject adject;
    struct s_letter_node_vrb_adject* sons[ALPHABET];

}t_letter_node_adject, * p_letter_node_adject;

typedef struct s_tree_adject
{
    p_letter_node_adject root;
}t_tree_adject;

p_letter_node_adject createLetterNodeAdject(char letter);
t_tree_adject createEmptyTreeAdject();

t_tree_adject generateTreeAdject(FILE* filename);

void generateAdject(t_tree_adject tree);

#endif //PROJET_GENERATEUR_TREE_ADJECT_H
