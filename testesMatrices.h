#ifndef TESTESMATRICES_H_INCLUDED
#define TESTESMATRICES_H_INCLUDED

#include <stdbool.h>
#include "matrice.h"

bool sont_MatricesMemeTaille(matrice *M, matrice *N);
bool sont_MatricesEgales(matrice *M, matrice *N);
bool est_MatriceCarree(matrice *M);
bool est_MatriceNulle(matrice *M);
bool est_MatriceIdentite(matrice *M);
bool est_MatriceTriangulaireSup(matrice *M);
bool est_MatriceTriangulaireInf(matrice *M);
bool est_MatriceTriangulaire(matrice *M);
bool est_MatriceDiagonale(matrice *M);

#endif // TESTESMATRICES_H_INCLUDED
