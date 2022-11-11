//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_VERBE_H
#define PROJET_GENERATEUR_TREE_VERBE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"


typedef struct fl_vrb
{
    char* forme_conj; // forme conjuguée
    char* infinitif; // forme à l'infinitif
    char pers[2]; // je/tu/il/...
    char nombre_gr[2]; // singulier/ pluriel
    char temps[6]; // Passé present
}fl_vrb;

typedef struct maillon_l_fl_vrb
{
    fl_vrb value;
    struct maillon_fl_vrb *next;
} *p_fl_vrb;

typedef struct s_std_list_vrb
{
    p_fl_vrb head;
} l_fl_vrb;

typedef struct s_letter_node_vrb
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    int end_word;
    l_fl_vrb verbe;
    struct s_letter_node_vrb* sons[ALPHABET];

}t_letter_node_vrb, * p_letter_node_vrb;

typedef struct s_tree_vrb
{
    p_letter_node_vrb root;
}t_tree_vrb;


p_letter_node_vrb createLetterNodeVerb(char letter);
t_tree_vrb createEmptyTreeVerb();

t_tree_vrb generateTreeVerb(FILE* filename);

void generateVerb(t_tree_vrb tree);

#endif //PROJET_GENERATEUR_TREE_VERBE_H
