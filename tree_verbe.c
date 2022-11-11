//
// Created by kevmu on 28/10/2022.
//

#include "tree_verbe.h"
#include "txt_fonctions.h"


p_letter_node_vrb createLetterNodeVerb(char letter)
{
    p_letter_node_vrb nouv;
    nouv = (p_letter_node_vrb) malloc(sizeof(t_letter_node_vrb));
    nouv->lettre = letter;
    nouv->end_word = 0;
    nouv->nb_formes = 0;
    for (int i = 0; i < ALPHABET; i++)
    {
        nouv->sons[i] = NULL;
    }
    return nouv;
}

t_tree_vrb createEmptyTreeVerb()
{
    t_tree_vrb tree;
    tree.root = createLetterNodeVerb('/');
    return tree;
}

t_tree_vrb generateTreeVerb(FILE* filename)
{
    t_tree_vrb tree = createEmptyTreeVerb();
    p_letter_node_vrb temp = tree.root;
    int cpt= 0;

    FILE *file = fopen(filename, "r");
    char texte[256];

    while (fgets(texte, 255, file) != NULL) {
        char ligne[256];
        strcpy(ligne, texte);
        char d[] = "\t";
        char *portion1 = strtok(texte, d);
        char *portion2 = strtok(NULL, d);
        char *portion3 = strtok(NULL, ":");

        if (strcmp(portion3, "Ver") == 0)
        {
            while (portion2[cpt] != '\0')
            {
                if (temp->sons[convertCharInInt(portion2[cpt])] == NULL)
                {
                    temp->sons[convertCharInInt(portion2[cpt])] = createLetterNodeVerb(portion2[cpt]);
                    temp = temp->sons[convertCharInInt(portion2[cpt])];
                    cpt++;
                }
                else
                {
                    temp = temp->sons[convertCharInInt(portion2[cpt])];
                    cpt++;
                }

            }
            temp->nb_formes++;
            temp->end_word = 1;
            temp = tree.root;
            cpt = 0;
        }
    }
    fclose(file);
    return tree;
}

void generateVerb(t_tree_vrb tree)
{
    p_letter_node_vrb temp = tree.root;
    int n;

    while(temp->end_word != 1)
    {
        n = rand()%27;
        if(temp->sons[n] != NULL)
        {
            temp=temp->sons[n];
            printf("%c",temp->lettre);

        }

    }
    printf(" ");
}
