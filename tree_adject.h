//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADJECT_H
#define PROJET_GENERATEUR_TREE_ADJECT_H
#define ALPHABET 26

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

typedef struct s_std_list
{
    p_fl_adject head;
} l_fl_adject;

typedef struct noeud_adject
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    l_fl_adject adject;
    struct noeud_adject* sons[ALPHABET];

}noeud_adject;

typedef struct arbre_adject
{
    noeud_adject root;
}tree_adject;


#endif //PROJET_GENERATEUR_TREE_ADJECT_H
