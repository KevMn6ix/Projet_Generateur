//
// Created by kevmu on 28/10/2022.
//

#ifndef PROJET_GENERATEUR_TREE_ADV_H
#define PROJET_GENERATEUR_TREE_ADV_H
#define ALPHABET 26

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

typedef struct s_std_list
{
    p_fl_adv head;
} l_fl_adv;

typedef struct noeud_adv
{
    char lettre;
    int nb_formes; // nombre formes_flechies
    l_fl_adv adverbes;
    struct noeud_adv* sons[ALPHABET];

}noeud_adv;

typedef struct arbre_adv
{
    noeud_adv root;
}tree_adv;



#endif //PROJET_GENERATEUR_TREE_ADV_H
