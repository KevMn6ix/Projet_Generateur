//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_VERBE_H
#define PROJET_GENERATEUR_TREE_VERBE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des verbes
struct s_cell_vrb
{
    char* forme_conj; //Forme conjuguée

    char* pers1; // je/tu/il/...
    char* sing_plur1; // singulier/ pluriel
    char* temps1; // Passé present
    char* pers2; // je/tu/il/...
    char* sing_plur2; // singulier/ pluriel
    char* temps2; // Passé present
    char* pers3; // je/tu/il/...
    char* sing_plur3; // singulier/ pluriel
    char* temps3; // Passé present
    char* pers4; // je/tu/il/...
    char* sing_plur4; // singulier/ pluriel
    char* temps4; // Passé present
    char* pers5; // je/tu/il/...
    char* sing_plur5; // singulier/ pluriel
    char* temps5; // Passé present
    char* pers6; // je/tu/il/...
    char* sing_plur6; // singulier/ pluriel
    char* temps6; // Passé present

    struct s_cell_vrb *next; //On initialise un maillon suivant

};
typedef struct s_cell_vrb t_cell_vrb, *p_cell_vrb;//On définit un pointeur sur une cellule (p_cell_vrb)

//On définit notre liste chaînée de formes fléchies
typedef struct s_std_list_vrb
{
    p_cell_vrb head; //On définit la tête de notre liste
}t_std_list_vrb;

//On définit les noeud de notre arbre des verbes
typedef struct s_letter_node_vrb
{
    char lettre; //On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_formes; //On initialise une variable qui va stocker le nombre de formes fléchies du nom de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_std_list_vrb verbes; //On initialise la liste chaînée de nos formes fléchies
    struct s_letter_node_vrb* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_vrb, *p_letter_node_vrb;

//On définit une structure qui va correspondre à notre arbre de verbes
typedef struct s_tree_vrb
{
    p_letter_node_vrb root;
}t_tree_vrb;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_vrb createLetterNodeVerb(char letter);
//Cette fonction permet de créer un arbre de verbes vide
t_tree_vrb createEmptyTreeVerb();

//Cette fonction permet de créer un nouveau maillon de notre liste chaînée à l'aide des informations de la forme fléchie du verbe
p_cell_vrb createCellVerb(char* forme_conj, char* infinitif, char* temps1, char* sing_plur1, char* personne1, char* temps2, char* sing_plur2, char* personne2, char* temps3, char* sing_plur3, char* personne3, char* temps4, char* sing_plur4, char* personne4, char* temps5, char* sing_plur5, char* personne5, char* temps6, char* sing_plur6, char* personne6);
//Cette fonction permet de générer un arbre de verbes de base à l'aide d'un dictionnaire
t_tree_vrb generateTreeVerb(FILE* filename);

//Cette fonction permet de générer un verbe de base à partir d'un arbre de verbes
void generateVerb(t_tree_vrb tree);

#endif //PROJET_GENERATEUR_TREE_VERBE_H
