#ifndef OPERATIONSELEMENTAIRES_H_INCLUDED
#define OPERATIONSELEMENTAIRES_H_INCLUDED

#include "matrice.h"

void echangeLigne(matrice *M, int l1, int l2);
void eliminationSurLigne(matrice *M, int i, int k);
void combinaisonParAutreLigne(matrice *M, CORPS lambda, int l, int lc);

#endif // OPERATIONSELEMENTAIRES_H_INCLUDED
