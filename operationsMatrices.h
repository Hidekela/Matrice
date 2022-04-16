#ifndef OPERATIONSMATRICES_H_INCLUDED
#define OPERATIONSMATRICES_H_INCLUDED

#include <stdbool.h>
#include "matrice.h"

void matriceNulle(matrice *M);
void matriceIdentite(matrice *M);
void matriceCopier(matrice *M, matrice *Mprim);
void matricesAddition(matrice *M_plus_N, matrice *M, matrice *N);
void matriceProduitParScalaire(CORPS scalaire, matrice *M);
void matricesProduit(matrice *M_fois_N, matrice *M, matrice *N);
void matricePuissance(matrice *M_exp_n, matrice *M, int n);
void matriceEchelonner(matrice *M_echelonnee, matrice *M);
bool matriceDeterminant(matrice *M, CORPS *det);
void matriceInverse(matrice *M_inverse, matrice *M);

#endif // OPERATIONSMATRICES_H_INCLUDED
