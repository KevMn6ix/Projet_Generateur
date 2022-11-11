//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_NOM_H
#define PROJET_GENERATEUR_TREE_NOM_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

typedef struct fl_nom
{
    int nb_formes; // Nombre de formes flechies
    char* nom_fl; // forme flechie du nom
    char genre[3]; // Masculin/feminin
    char nombre_gr[2]; //Nombre grammatical : singulier/ pluriel
}fl_nom;

typedef struct maillon_l_fl_nom
{
    fl_nom value;
    struct maillon_fl_nom *next;
} *p_fl_nom;

typedef struct s_std_list_nom
{
    p_fl_nom head;
} l_fl_nom;

typedef struct s_letter_node_nom
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    int end_word;
    l_fl_nom nom;
    struct s_letter_node_nom* sons[ALPHABET];

}t_letter_node_nom, * p_letter_node_nom;

typedef struct arbre_verbe
{
    p_letter_node_nom root;
}t_tree_nom;

p_letter_node_nom createLetterNodeNom(char letter);
t_tree_nom createEmptyTreeNom();

t_tree_nom generateTreeNom(FILE* filename);


void generateNom(t_tree_nom tree);
#endif //PROJET_GENERATEUR_TREE_NOM_H
