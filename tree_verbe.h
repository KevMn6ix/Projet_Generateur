//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_VERBE_H
#define PROJET_GENERATEUR_TREE_VERBE_H
#define ALPHABET 26


typedef struct fl_vrb
{
    char* forme_conj; // forme conjuguée
    char pers[2]; // Masculin/feminin
    char nombre_gr[2]; // singulier/ pluriel
    char temps[6]; // Passé present
}fl_vrb;

typedef struct maillon_l_fl_vrb
{
    fl_vrb value;
    struct maillon_fl_vrb *next;
} *p_fl_vrb;

typedef struct s_std_list
{
    p_fl_vrb head;
} l_fl_vrb;

typedef struct noeud_vrb
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    l_fl_vrb verbe;
    struct noeud_vrb* sons[ALPHABET];

}noeud_vrb;

typedef struct arbre_verbe
{
    noeud_vrb root;
}tree_vrb;

#endif //PROJET_GENERATEUR_TREE_VERBE_H
