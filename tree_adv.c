//
// Created by Aurelien on 11/14/2022.
//

#include "tree_adv.h"
#include "txt_fonctions.h"

//Cette fonction permet de créer un nouveau d'adverbe noeud à l'aide d'une lettre en entrée
p_letter_node_adv createLetterNodeAdv(char letter)
{
    p_letter_node_adv nouv = (p_letter_node_adv) malloc(sizeof(t_letter_node_adv)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre d'adverbes vide
t_tree_adv createEmptyTreeAdv()
{
    t_tree_adv tree; //On initialise notre arbre
    tree.root = createLetterNodeAdv('/'); //On crée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de générer un arbre d'adverbes l'aide d'un dictionnaire
t_tree_adv generateTreeAdv(FILE* filename)
{
    t_tree_adv tree = createEmptyTreeAdv(); //On initialise un arbre vide
    p_letter_node_adv temp_node_adv = tree.root; //On initialise une variable temporaire afin de parcourir notre arbre

    int cpt = 0; //On initialise un compteur permettant de parcourir la forme de base de l'adverbe

    FILE *file = fopen((const char *) filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire

    while (fgets(texte, 255, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t \n"; //On définit les délimiteurs de notre ligne
        char *adverbe = strtok(texte, d); //On récupère l'adverbe
        char *forme_base = strtok(NULL, d);//On récupère la forme de base de l'adverbe
        char *type_mot = strtok(NULL, d);//On récupère le type de mot de notre adverbe

        if (strcmp(type_mot, "Adv") == 0) //On vérifie si le type de mot est un Adv
        {

            while(adverbe[cpt] != '\0') //On initialise une boucle afin de parcourir notre forme de base
            {

                if (temp_node_adv->sons[convertCharInInt(adverbe[cpt])] == NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_adv->sons[convertCharInInt(adverbe[cpt])] = createLetterNodeAdv(adverbe[cpt]); //alors on va créer un nouveau noeud
                    temp_node_adv = temp_node_adv->sons[convertCharInInt(adverbe[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }
                else
                {
                    temp_node_adv = temp_node_adv->sons[convertCharInInt(adverbe[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_adv->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            temp_node_adv = tree.root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }
    }
    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
    return tree; //On retourne notre arbre de noms de base
}

//Cette fonction permet de générer un adverbe à partir d'un arbre d'adverbes
void generateAdv(t_tree_adv tree)
{
    p_letter_node_adv temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26
    while(temp->end_word != 1) //Tant que nous sommes à la fin d'un nom
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
