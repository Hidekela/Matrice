#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#define CORPS double

typedef struct matrice
{
    int ligne;
    int colonne;
    CORPS **coefficient;
} matrice;

void allocationErreur(void *ptr);
matrice* creerMatrice(int ligne, int colonne);
void detruireMatrice(matrice *M);
void afficheMatrice(matrice *M);
void saisieMatrice(matrice *M);

#include "testesMatrices.h"
#include "operationsMatrices.h"

#endif // MATRICE_H_INCLUDED
