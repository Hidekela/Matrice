#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

/**
 * @brief Permet de saisir plusieurs "doubles" sur une seule ligne dans l'entrée standard, séparé par un 
 * caractère donné "splitter" et le stocke dans un tableau de doubles
 * 
 * @param tableau le tableau recevant les doubles
 * @param taille la taille du tableau (donc le nombre total de "doubles" saisis)
 * @param splitter le séparateur des doubles
 */
void scanSplitDoubles(double *tableau, int taille, char splitter)
{
    int i;
    char text[255], *start = NULL;
    
    fgets(text,255,stdin);
    start = text;

    for(i = 0; i < taille; i++)
    {
        tableau[i] = strtod(start,NULL);
        start = strchr(start,splitter);
        if(start != NULL)
            start++;
        else
            break;
    }
    for(i++; i < taille; i++)
    {
        tableau[i] = 0.0;
    }
}