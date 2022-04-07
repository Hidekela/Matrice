#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrice.h"

/**
 * @brief Arrête le programme en cas d'erreur d'allocation de mémoire
 * 
 * @param ptr le pointeur à tester
 */
void allocationErreur(void *ptr)
{
    if(ptr == NULL)
    {
        fputs("Erreur d'allocation de mémoire!\n",stderr);
        system("pause");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Crée une matrice (nulle initialement) de dimension donnée et renvoie un pointeur vers ce matrice
 * 
 * @param ligne ligne de la matrice
 * @param colonne colonne de la matrice
 * @return matrice* Le pointeur de la matrice
 */
matrice* creerMatrice(int ligne, int colonne)
{
    if(ligne < 1 || colonne < 1)
    {
        puts("Erreur: le nombre de ligne et de colonne doivent etre strictement positif!");
        return NULL;
    }

    int i;
    matrice *M = NULL;

    M = malloc(sizeof(matrice));

    allocationErreur((matrice*) M);

    M->colonne = colonne;
    M->ligne = ligne;
    
    M->coefficient = calloc(ligne,sizeof(CORPS*));

    allocationErreur((CORPS **) M->coefficient);

    for(i = 0; i < ligne; i++)
    {
        M->coefficient[i] = calloc(colonne,sizeof(CORPS));
        allocationErreur((CORPS*) M->coefficient[i]);
    }

    // matriceNulle(M);
    return M;
}

/**
 * @brief Detruit une matrice (la libérer de la mémoire)
 * 
 * @param M la matrice à libérer
 */
void detruireMatrice(matrice *M)

{
    int i;

    for(i = 0; i < M->ligne; i++)
    {
        free(M->coefficient[i]);
    }

    free(M->coefficient);
    free(M);
}

/**
 * @brief Affiche le contenu d'une matrice
 * 
 * @param M la matrice à afficher
 */
void afficheMatrice(matrice *M)
{
    int i,j;
    puts("\n");
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            printf("%f\t",M->coefficient[i][j]);
        }
        puts("\n");
    }
}

/**
 * @brief Saisie les coefficients d'une matrice
 * 
 * @param M la matrice à saisir
 */
void saisieMatrice(matrice *M)
{
    int i,j;
    char a[16];
    puts("\n");
    
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            printf("[%d][%d] : ",i+1,j+1);
            fgets(a,16,stdin);
            M->coefficient[i][j] = strtod(a,NULL);
        }
    }
}
