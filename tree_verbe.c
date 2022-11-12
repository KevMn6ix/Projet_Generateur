//
// Created by kevmu on 28/10/2022.
//

#include "tree_verbe.h"
#include "txt_fonctions.h"

//Cette fonction permet de créér un nouveau noeud à l'aide d'une lettre en entrée
p_letter_node_vrb createLetterNodeVerb(char letter)
{
    p_letter_node_vrb nouv = (p_letter_node_vrb) malloc(sizeof(t_letter_node_vrb)); //On initialise notre noeud et on alloue la mémoire
    nouv->lettre = letter; //On ajoute notre caractère dans le noeud
    nouv->end_word = 0; //On initialise notre indicateur de fin de mot à 0
    nouv->nb_formes = 0; //On initialise notre compteur de formes fléchies à 0
    nouv->verbes.head = NULL; //On initialise notre tete de liste chaînée à NULL
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL; //On initialise chaque fils de notre noeud à NULL
    }
    return nouv; //On retourne notre noeud
}

//Cette fonction permet de créer un arbre de verbes vide
t_tree_vrb createEmptyTreeVerb()
{
    t_tree_vrb tree; //On initialise notre arbre
    tree.root = createLetterNodeVerb('/'); //On créée la racine de notre arbre contenant le caractère '\'
    return tree; //On retourne notre arbre
}

//Cette fonction permet de créer un nouveau maillon de notre liste chaînée à l'aide des informations de la forme fléchie du verbe
p_cell_vrb createCellVerb(char* forme_conj, char* infinitif, char* temps1, char* sing_plur1, char* personne1, char* temps2, char* sing_plur2, char* personne2, char* temps3, char* sing_plur3, char* personne3, char* temps4, char* sing_plur4, char* personne4, char* temps5, char* sing_plur5, char* personne5, char* temps6, char* sing_plur6, char* personne6)
{
    p_cell_vrb new = (p_cell_vrb) malloc(sizeof (t_cell_vrb)); //On initialise un pointeur sur notre nouvelle cellule

    new->forme_conj = forme_conj; //On ajoute la forme conjugée dans notre cellule

    new->temps1 = temps1; //On ajoute le premier temps dans notre cellule
    new->sing_plur1 = sing_plur1; //On ajoute le premier nombre gramatical dans notre cellule
    new->pers1 = personne1; //On ajoute la première personne dans notre cellule

    //On ajoute les autres informations de notre verbe conjugée si elles ne sont pas nulles
    if(temps2 != NULL && sing_plur2 != NULL && personne2 != NULL)
    {
        new->temps2 = temps2;
        new->sing_plur2 = sing_plur2;
        new->pers2 = personne2;

    }

    if(temps2 == NULL || sing_plur2 == NULL || personne2 != NULL)
    {
        new->temps2 = NULL;
        new->sing_plur2 = NULL;
        new->pers2 = NULL;
    }

    if(temps3 != NULL && sing_plur3 != NULL && personne3 != NULL)
    {
        new->temps3 = temps3;
        new->sing_plur3 = sing_plur3;
        new->pers3 = personne3;
    }

    if(temps3 == NULL || sing_plur3 == NULL || personne3 != NULL)
    {
        new->temps3 = NULL;
        new->sing_plur3 = NULL;
        new->pers3 = NULL;
    }

    if(temps4 != NULL && sing_plur4 != NULL && personne4 != NULL)
    {
        new->temps4 = temps4;
        new->sing_plur4 = sing_plur4;
        new->pers4 = personne4;
    }

    if(temps4 == NULL || sing_plur4 == NULL || personne4 != NULL)
    {
        new->temps4 = NULL;
        new->sing_plur4 = NULL;
        new->pers4 = NULL;
    }

    if(temps5 != NULL && sing_plur5 != NULL && personne5 != NULL)
    {
        new->temps5 = temps5;
        new->sing_plur5 = sing_plur5;
        new->pers5 = personne5;
    }

    if(temps5 == NULL || sing_plur5 == NULL || personne5 != NULL)
    {
        new->temps5 = NULL;
        new->sing_plur5 = NULL;
        new->pers5 = NULL;
    }

    if(temps6 != NULL && sing_plur6 != NULL && personne6 != NULL)
    {
        new->temps6 = temps6;
        new->sing_plur6 = sing_plur6;
        new->pers6 = personne6;
    }
    if(temps6 == NULL || sing_plur6 == NULL || personne6 != NULL)
    {
        new->temps6 = NULL;
        new->sing_plur6 = NULL;
        new->pers6 = NULL;
    }

    new->next = NULL;

    return new; //On retoune notre cellule
}

//Cette fonction permet de générer un arbre de verbes de base à l'aide d'un dictionnaire
t_tree_vrb generateTreeVerb(FILE* filename)
{
    t_tree_vrb tree = createEmptyTreeVerb(); //On initialise un arbre vide
    p_letter_node_vrb temp_node_verb = tree.root; //On initialise une variable temporaire afin de parcourir notre arbre
    p_cell_vrb temp_head_verbes; //On initialise une variable temporaire afin de parcourir nos listes de formes flechies

    int cpt= 0; //On initialise un compteur permettant de parcourir la forme de base de notre verbe

    FILE *file = fopen(filename, "r"); //On ouvre notre dictionnaire
    char texte[256]; //On initialise une variable qui va récupérer chaque ligne de notre dictionnaire

    while (fgets(texte, 256, file) != NULL) //On récupère les lignes de notre fichier dans la variable texte
    {
        char ligne[256]; //On initialise une variable afin de copier la ligne que nous lisons dans celle-ci
        strcpy(ligne, texte); //On copie la ligne en cours de lecture dans la variable ligne

        char d[] = "\t : +"; //On définit les délimiteurs de notre ligne
        char *verbe_conjuge = strtok(texte, d); //On récupère le verbe conjugé
        char *infinitif = strtok(NULL, d); //On récupère l'infinitif de notre verbe
        char *type_mot = strtok(NULL, d); //On récupère le type de mot de notre verbe

        //On récupère les temps, nombres grammaticaux et personnes de notre verbe (/!\ Il peut y en avoir plusieurs par formes fléchies)
        char *temps_verb1 = strtok(NULL, d);
        char *sing_plur1 = strtok(NULL,d);
        char *personne1 = strtok(NULL,d);

        char *temps_verb2 = strtok(NULL,d);
        char *sing_plur2 = strtok(NULL,d);
        char *personne2 = strtok(NULL,d);

        char *temps_verb3 = strtok(NULL,d);
        char *sing_plur3 = strtok(NULL,d);
        char *personne3 = strtok(NULL,d);

        char *temps_verb4 = strtok(NULL,d);
        char *sing_plur4 = strtok(NULL,d);
        char *personne4 = strtok(NULL,d);

        char *temps_verb5 = strtok(NULL,d);
        char *sing_plur5 = strtok(NULL,d);
        char *personne5 = strtok(NULL,d);

        char *temps_verb6 = strtok(NULL,d);
        char *sing_plur6 = strtok(NULL,d);
        char *personne6 = strtok(NULL,d);

        if (strcmp(type_mot, "Ver") == 0) //On vérifie si le type de mot est un Verbe
        {
            while (infinitif[cpt] != '\0') //On initialise une boucle afin de parcourir notre infinitif
            {

                if (temp_node_verb->sons[convertCharInInt(infinitif[cpt])] == NULL) //Si le noeud correspondant à notre lettre est NULL
                {
                    temp_node_verb->sons[convertCharInInt(infinitif[cpt])] = createLetterNodeVerb(infinitif[cpt]); //alors on va créer un nouveau noeud
                    temp_node_verb = temp_node_verb->sons[convertCharInInt(infinitif[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    cpt++; //On incrémente notre compteur
                }
                else
                {
                    temp_node_verb = temp_node_verb->sons[convertCharInInt(infinitif[cpt])]; //On entre dans le nouveau noeud à l'aide de notre pointeur
                    temp_head_verbes = temp_node_verb->verbes.head; //On ajoute dans notre variable temporaire la tete de la liste de formes flechies
                    cpt++; //On incrémente notre compteur
                }

            }

            //Lorsqu'on arrive à la fin de notre mot
            temp_node_verb->nb_formes++; //On incrémente de 1 notre compteur de formes fléchies
            temp_node_verb->end_word = 1; //On indique que nous sommes à la fin d'un mot à l'aide de notre indicateur

            if(temp_head_verbes == NULL) //Si la liste de verbes conjuguées est NULL
            {
                temp_node_verb->verbes.head = createCellVerb(verbe_conjuge,infinitif,temps_verb1,sing_plur1,personne1,temps_verb2,sing_plur2,personne2,temps_verb3,sing_plur3,personne3,temps_verb4,sing_plur4,personne4,temps_verb5,sing_plur5,personne5,temps_verb6,sing_plur6,personne6); //Alors on va créer une nouvelle cellule qui va être assignéé à la tête de la liste
            }
            else
            {
                while(temp_head_verbes->next != NULL) //Sinon tant que nous ne sommes pas à la fin de la liste
                {
                    temp_head_verbes = temp_head_verbes->next; //On va à la cellule suivante
                }
                temp_head_verbes->next = createCellVerb(verbe_conjuge,infinitif,temps_verb1,sing_plur1,personne1,temps_verb2,sing_plur2,personne2,temps_verb3,sing_plur3,personne3,temps_verb4,sing_plur4,personne4,temps_verb5,sing_plur5,personne5,temps_verb6,sing_plur6,personne6); //Quand nous sommes arrivé à la fin, on va créer une nouvelle cellule qui va être assignéé à la fin de la liste
            }

            temp_node_verb = tree.root; //On retourne à la racine de notre arbre
            cpt = 0; //On réinitialise notre compteur
        }

    }
    fclose(file); //On ferme notre dictionnaire quand nous sommes à la fin
    return tree; //On retourne notre arbre de verbes de base
}

//Cette fonction permet de générer un verbe de base à partir d'un arbre de verbes
void generateVerb(t_tree_vrb tree)
{
    p_letter_node_vrb temp = tree.root; //On initialise un pointeur afin de parcourir notre arbre
    int n; //On initialise un entier afin de générer un nombre aléatoire entre 0 et 26

    while(temp->end_word != 1) //Tant que nous sommes à la fin d'un verbe
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
