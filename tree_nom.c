//
// Created by kevmu on 28/10/2022.
//

#include "tree_nom.h"
#include "txt_fonctions.h"

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_nom createLetterNodeNom(char letter)
{
    p_letter_node_nom nouv = (p_letter_node_nom) malloc(sizeof(t_letter_node_nom)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    nouv->nb_formes = 0; //On initialise notre compteur de formes fléchies à 0
    nouv->noms.head = NULL; //On initialise notre tete de liste chaînée à NULL
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre de noms vide
t_tree_nom createEmptyTreeNom()
{
    t_tree_nom tree; //On initialise notre arbre
    tree.root = createLetterNodeNom('/'); //On créée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de créer un nouveau maillon de notre liste chaînée à l'aide des informations de la forme fléchie du nom
p_cell_nom createCellNom(char* nom, char* genre,char* sing_plur)
{
    p_cell_nom new = (p_cell_nom) malloc(sizeof (t_cell_nom)); //On initialise un pointeur sur notre nouvelle cellule

    new->nom = nom; //On ajoute le nom dans notre cellule
    new->genre = genre; //On ajoute le genre dans notre cellule
    new->sing_plur = sing_plur; //On ajoute le nombre gramatical dans notre cellule
    new->next = NULL; //On initialise la cellule suivante à NULL

    return new; //On retourne notre cellule
}

//Cette fonction permet de générer un arbre de noms de base à l'aide d'un dictionnaire
t_tree_nom generateTreeNom(FILE* filename)
{
    t_tree_nom tree = createEmptyTreeNom(); //On initialise un arbre vide
    p_letter_node_nom temp_node_nom = tree.root; //On initialise une variable temporaire afin de parcourir notre arbre
    p_cell_nom temp_head_noms; //On initialise une variable temporaire afin de parcourir nos listes de formes flechies

    int cpt = 0; //On initialise un compteur permettant de parcourir la forme de base de nom

    FILE *file = fopen((const char *) filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire

    while (fgets(texte, 255, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t : +"; //On définit les délimiteurs de notre ligne
        char *nom = strtok(texte, d); //On récupère le nom
        char *forme_base = strtok(NULL, d); //On récupère la forme de base
        char *type_mot= strtok(NULL, d);//On récupère le type de mot de notre nom
        char *genre= strtok(NULL, d); //On récupère le genre de notre nom
        char *sing_plur = strtok(NULL,d);//On récupère le nombre grammatical de notre adjectif

        if (strcmp(type_mot, "Nom") == 0) //On vérifie si le type de mot est un Nom
        {
            while (forme_base[cpt] != '\0') //On initialise une boucle afin de parcourir notre forme de base
            {
                if (temp_node_nom->sons[convertCharInInt(forme_base[cpt])] == NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_nom->sons[convertCharInInt(forme_base[cpt])] = createLetterNodeNom(forme_base[cpt]); //alors on va créer un nouveau noeud
                    temp_node_nom = temp_node_nom->sons[convertCharInInt(forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }
                else
                {
                    temp_node_nom = temp_node_nom->sons[convertCharInInt(forme_base[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    temp_head_noms = temp_node_nom->noms.head; //On ajoute dans notre variable temporaire la tete de la liste de formes flechies
                    cpt++; //On incrémente notre compteur
                }

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_nom->nb_formes++; //On incrémente de 1 notre compteur de formes fléchies
            temp_node_nom->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            if(temp_head_noms == NULL) //Si la liste de noms est NULL
            {
                temp_node_nom->noms.head = createCellNom(nom,genre,sing_plur); //Alors on va créer une nouvelle cellule qui va être assignéé à la tête de la liste
            }
            else
            {
                while(temp_head_noms->next != NULL) //Sinon tant que nous ne sommes pas à la fin de la liste
                {
                    temp_head_noms = temp_head_noms->next; //On va à la cellule suivante
                }
                temp_head_noms->next = createCellNom(nom,genre,sing_plur); //Quand nous sommes arrivé à la fin, on va créer une nouvelle cellule qui va être assignéé à la fin de la liste
            }

            temp_node_nom = tree.root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }
    }
    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
    return tree; //On retourne notre arbre de noms de base
}

//Cette fonction permet de générer un nom de base à partir d'un arbre de noms
void generateNom(t_tree_nom tree)
{
    p_letter_node_nom temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
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
