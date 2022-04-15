#include <stdio.h>
#include "operationsElementaires.h"

/**
 * @brief Echange deux lignes d'une matrice (et change le signe de l'un de la ligne)
 * 
 * @param M la matrice
 * @param l1 la ligne
 * @param l2 l'autre ligne
 */
void echangeLigne(matrice *M, int l1, int l2)
{
    int j;
    CORPS temp;

    for(j = 0; j < M->colonne; j++)
    {
        temp = M->coefficient[l1][j];
        M->coefficient[l1][j] = M->coefficient[l2][j];
        M->coefficient[l2][j] = temp == 0.0? temp : -temp; // Pour enlever le "-" du 0 (-0.000000) :|
    }
}

/**
 * @brief Elimine un coefficient (de position i,k) d'une matrice (le rendre 0)
 *  et applique des changements sur les autres colonne de la même ligne
 * 
 * @param M la matrice
 * @param i la ligne du coefficient à éliminer
 * @param k la colonne du coefficient à éliminer
 */
void eliminationSurLigne(matrice *M, int i, int k)
{
    if(M->coefficient[i][k] == 0)
        return;
    else if(M->coefficient[k][k] == 0)
    {
        echangeLigne(M,k,i);
        return;
    }

    int j;
    CORPS lambda = M->coefficient[i][k] / M->coefficient[k][k];

    for(j = 0; j < M->colonne; j++)
        M->coefficient[i][j] -= lambda * M->coefficient[k][j];
        // a_(i)(j) <-- a_(i)(j) - a_(k)(j) x a_(i)(k)/a(k)(k), voir matrice d'élimination
}

/**
 * @brief Ajoute à la ligne l un multiple d'une autre ligne lc (l <-- l + lambda x lc) à une matrice
 * 
 * @param M la matrice
 * @param lambda un multiple
 * @param l la ligne
 * @param lc l'autre ligne
 */
void combinaisonParAutreLigne(matrice *M, CORPS lambda, int l, int lc)
{
    if(lambda == 0)
    {
        puts("Erreur: lambda doit etre non nul!");
        return;
    }

    int j;
    for(j = 0; j < M->colonne; j++)
    {
        M->coefficient[l][j] += lambda * M->coefficient[lc][j];
    }
}

/**
 * @brief Multiplie une ligne d'une matrice par un scalaire non nul
 * 
 * @param M la matrice
 * @param lambda le scalaire
 * @param l la ligne
 */
void produitScalaireLigne(matrice *M, CORPS lambda, int l)
{
    if(lambda == 0)
    {
        puts("Erreur: lambda doit etre non nul!");
        return;
    }

    int j;
    for(j = 0; j < M->colonne; j++)
    {
        M->coefficient[l][j] *= lambda;
    }
}
