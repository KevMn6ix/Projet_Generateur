//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_NOM_H
#define PROJET_GENERATEUR_TREE_NOM_H
#define ALPHABET 26


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

typedef struct s_std_list
{
    p_fl_nom head;
} l_fl_nom;

typedef struct noeud_nom
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    l_fl_nom nom;
    struct noeud_nom* sons[ALPHABET];

}noeud_nom;

typedef struct arbre_verbe
{
    noeud_nom root;
}tree_nom;


#endif //PROJET_GENERATEUR_TREE_NOM_H
