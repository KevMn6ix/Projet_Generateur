//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_NOM_H
#define PROJET_GENERATEUR_TREE_NOM_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "txt_fonctions.h"

//On définit les maillons de notre liste chaîne qui va contenir les formes fléchies des noms
struct s_cell_nom
{
    char* nom; //Forme fléchie du nom
    char* genre; //Genre du nom
    char* sing_plur; //Nombre grammatical de l'adjectif

    struct s_cell_nom *next; //On initialise un maillon suivant
};

typedef struct s_cell_nom t_cell_nom, *p_cell_nom;//On définit un pointeur sur une cellule (p_cell_nom)

//On définit notre liste chaînée de formes fléchies
typedef struct s_std_list_nom
{
    p_cell_nom head; //On définit la tête de notre liste
}t_std_list_nom;

//On définit les noeud de notre arbre des adjectifs
typedef struct s_letter_node_nom
{
    char lettre;//On initialise une variable permettant de stocker la lettre de notre noeud
    int nb_formes; //On initialise une variable qui va stocker le nombre de formes fléchies du nom de base
    int end_word; //On initialise un entier permettant de savoir si nous sommes à la fin d'un mot ou non
    t_std_list_nom noms; //On initialise la liste chaînée de nos formes fléchies
    struct s_letter_node_nom* sons[ALPHABET]; //On initialise les fils de notre noeud

}t_letter_node_nom, *p_letter_node_nom;

//On définit une structure qui va correspondre à notre arbre de noms
typedef struct s_tree_nom
{
    p_letter_node_nom root;
}t_tree_nom;

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_nom createLetterNodeNom(char letter);
//Cette fonction permet de créer un arbre de noms vide
t_tree_nom createEmptyTreeNom();

//Cette fonction permet de créer un nouveau maillon de notre liste chaînée à l'aide des informations de la forme fléchie du nom
p_cell_nom createCellNom(char* nom, char* genre,char* sing_plur);
//Cette fonction permet de générer un arbre de noms de base à l'aide d'un dictionnaire
t_tree_nom generateTreeNom(FILE* filename);

//Cette fonction permet de générer un nom de base à partir d'un arbre de noms
void generateNom(t_tree_nom tree);

#endif //PROJET_GENERATEUR_TREE_NOM_H
