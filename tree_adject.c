//
// Created by kevmu on 28/10/2022.
//

#include "tree_adject.h"
#include "txt_fonctions.h"

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_adject createLetterNodeAdject(char letter)
{
    p_letter_node_adject nouv = (p_letter_node_adject) malloc(sizeof(t_letter_node_adject)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    nouv->nb_formes = 0; //On initialise notre compteur de formes fléchies à 0
    nouv->adjectifs.head = NULL; //On initialise notre tete de liste chaînée à NULL
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre d'ajectifs vide
t_tree_adject createEmptyTreeAdject()
{
    t_tree_adject tree; //On initialise notre arbre
    tree.root = createLetterNodeAdject('/'); //On créée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de créer un nouveau maillon de notre liste chaînée à l'aide des informations de la forme fléchie de l'adjectif
p_cell_adj createCellAdj(char* adjectif, char* genre,char* sing_plur)
{
    p_cell_adj new = (p_cell_adj) malloc(sizeof (t_cell_adj)); //On initialise un pointeur sur notre nouvelle cellule

    new->adjectif = adjectif; //On ajoute l'adjectif dans notre cellule
    new->genre = genre; //On ajoute le genre dans notre cellule
    new->sing_plur = sing_plur; //On ajoute le nombre gramatical dans notre cellule
    new->next = NULL; //On initialise la cellule suivante à NULL

    return new; //On retoune notre cellule
}
//Cette fonction permet de générer un arbre d'ajectifs de base à l'aide d'un dictionnaire
t_tree_adject generateTreeAdject(FILE* filename)
{
    t_tree_adject tree = createEmptyTreeAdject(); //On initialise un arbre vide
    p_letter_node_adject temp_node_adj = tree.root; //On initialise une variable temporaire afin de parcourir notre arbre
    p_cell_adj temp_head_adjectifs; //On initialise une variable temporaire afin de parcourir nos listes de formes flechies

    int cpt = 0; //On initialise un compteur permettant de parcourir la forme de base de adjectif

    FILE *file = fopen(filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire

    while (fgets(texte, 255, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t : +"; //On définit les délimiteurs de notre ligne
        char *adjectif = strtok(texte, d); //On récupère l'adjectif
        char *forme_base = strtok(NULL, d); //On récupère la forme de base
        char *type_mot = strtok(NULL, d);//On récupère le type de mot de notre adjectif
        char *genre= strtok(NULL, d); //On récupère le genre de notre adjectif
        char *sing_plur = strtok(NULL,d); //On récupère le nombre grammatical de notre adjectif

        if (strcmp(type_mot, "Adj") == 0) //On vérifie si le type de mot est un Adjectif
        {
            while (forme_base[cpt] != '\0') //On initialise une boucle afin de parcourir notre forme de base
            {
                if (temp_node_adj->sons[convertCharInInt(forme_base[cpt])] == NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_adj->sons[convertCharInInt(forme_base[cpt])] = createLetterNodeAdject(forme_base[cpt]); //alors on va créer un nouveau noeud
                    temp_node_adj = temp_node_adj->sons[convertCharInInt(forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    temp_head_adjectifs = temp_node_adj->adjectifs.head;
                    cpt++; //On incrémente notre compteur
                }
                else
                {
                    temp_node_adj = temp_node_adj->sons[convertCharInInt(forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    temp_head_adjectifs = temp_node_adj->adjectifs.head; //On ajoute dans notre variable temporaire la tete de la liste de formes flechies
                    cpt++; //On incrémente notre compteur
                }

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_adj->nb_formes++; //On incrémente de 1 notre compteur de formes fléchies
            temp_node_adj->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            if(temp_head_adjectifs == NULL) //Si la liste de d'adjectifs est NULL
            {
                temp_node_adj->adjectifs.head = createCellAdj(adjectif,genre,sing_plur); //Alors on va créer une nouvelle cellule qui va être assignéé à la tête de la liste
            }
            else
            {
                while(temp_head_adjectifs->next != NULL) //Sinon tant que nous ne sommes pas à la fin de la liste
                {
                    temp_head_adjectifs = temp_head_adjectifs->next; //On va à la cellule suivante
                }
                temp_head_adjectifs->next = createCellAdj(adjectif,genre,sing_plur); //Quand nous sommes arrivé à la fin, on va créer une nouvelle cellule qui va être assignéé à la fin de la liste
            }

            temp_node_adj = tree.root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }
    }
    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
    return tree; //On retourne notre arbre d'adjectifs de base
}

//Cette fonction permet de générer un adjectif de base à partir d'un arbre d'adjectifs
void generateAdject(t_tree_adject tree)
{
    p_letter_node_adject temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

    while(temp->end_word != 1) //Tant que nous sommes à la fin d'un adjectif
    {
        n = rand()%27; //On génère un nombre aléatoire entre 0 et 26
        if(temp->sons[n] != NULL) //Si le noeud que nous avons choisi aléatoirement n'est pas NULL
        {
            temp=temp->sons[n]; //Alors on entre dans ce noeud
            printf("%c",temp->lettre); //On affiche la lettre de notre noeud
        }
    }
    printf(" ");


}

