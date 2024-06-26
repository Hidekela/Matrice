#include <stdio.h>
#include "operationsMatrices.h"
#include "testesMatrices.h"
#include "operationsElementaires.h"

/**
 * @brief Transforme une matrice quelconque en une matrice nulle
 * 
 * @param M pointeur de la matrice
 */
void matriceNulle(matrice *M)
{
    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            M->coefficient[i][j] = 0;
        }
    }
}

/**
 * @brief Transforme une matrice carree quelconque en une matrice identite
 * 
 * @param M pointeur de la matrice
 */
void matriceIdentite(matrice *M)
{
    if(!est_MatriceCarree(M))
    {
        puts("Erreur: la matrice n'est pas carree!");
        return;
    }

    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            if(i == j)
                M->coefficient[i][j] = 1;
            else
                M->coefficient[i][j] = 0;
        }
    }
}

/**
 * @brief Copie une matrice dans une autre
 * 
 * @param M la matrice à copier
 * @param Mprim la matrice qui reçoit
 */
void matriceCopier(matrice *M, matrice *Mprim)
{
    if(!sont_MatricesMemeTaille(M,Mprim))
    {
        puts("Erreur: la matrice qui recoit et la matrice a copier n'ont pas la meme taille!");
        return;
    }

    int i,j;

    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            Mprim->coefficient[i][j] = M->coefficient[i][j];
        }
    }
}

/**
 * @brief Additionne deux matrices
 * 
 * @param M_plus_N la matrice qui recevera M + N
 * @param M la première matrice
 * @param N l'autre matrice
 */
void matricesAddition(matrice *M_plus_N, matrice *M, matrice *N)
{
    // M + N est défini si est seulement si elles ont la même taille
    if(!sont_MatricesMemeTaille(M,N) || !sont_MatricesMemeTaille(M_plus_N,M))
    {
        puts("Erreur: les trois matrices n'ont pas la meme taille!");
        return;
    }

    int i,j;

    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            M_plus_N->coefficient[i][j] = M->coefficient[i][j] + N->coefficient[i][j];
        }
    }
}

/**
 * @brief Multiplie une matrice par un scalaire
 * 
 * @param scalaire le scalaire
 * @param M la matrice
 */
void matriceProduitParScalaire(CORPS scalaire, matrice *M)
{
    int i,j;

    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            M->coefficient[i][j] *= scalaire;
        }
    }
}

/**
 * @brief Multiplie une matrice par une autre. L'ordre doit être respecté: la sortie sera
 *  le produit de la matrice M x N où M est la première matrice, N est la seconde
 * 
 * @param M_fois_N la matrice qui recevera M x N
 * @param M la première matrice
 * @param N l'autre matrice
 */
void matricesProduit(matrice *M_fois_N, matrice *M, matrice *N)
{
    // MN est défini si est seulement si M->colonne == N->ligne
    if(M->colonne != N->ligne)
    {
        puts("Erreur: le nombre de colonne de la matrice a gauche n'est pas egale!");
        return;
    }
    else if(M_fois_N->colonne != N->colonne || M_fois_N->ligne != M->ligne)
    {
        puts("Erreur: verifier la taille de la matrice recevant!");
        return;
    }

    int i,j,k;
    // On crée une matrice temporaire pour éviter de modifier une matrice au cas où M_fois_N = M (=N)
    matrice *P = creerMatrice(M_fois_N->ligne,M_fois_N->colonne);
    
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < N->colonne; j++)
        {
            for(k = 0; k < N->ligne; k++) // ou M->colonne
            {
                P->coefficient[i][j] += M->coefficient[i][k] * N->coefficient[k][j];
            }
        }
    }

    matriceCopier(P,M_fois_N);

    detruireMatrice(P);
}

/**
 * @brief Elève une matrice à une certaine puissance
 * 
 * @param M_exp_n la matrice qui recevera M^n
 * @param M la matrice
 * @param n c'est la puissance, la puissance,.. xD
 */
void matricePuissance(matrice *M_exp_n, matrice *M, int n) // Mila amboarina ty refa puissance négatif
{
    if(!est_MatriceCarree(M))
    {
        puts("Erreur: la matrice n'est pas carree!");
        return;
    }
    else if(est_MatriceIdentite(M) || est_MatriceNulle(M) || n == 1)
    {
        matriceCopier(M,M_exp_n);
        return;
    }
    
    int i;

    matriceIdentite(M_exp_n);

    if(n <= 0)
    {
        return;
    }

    matricesProduit(M_exp_n,M,M);

    for(i = 2; i < n; i++)
    {
        matricesProduit(M_exp_n,M_exp_n,M);
    }
}

/**
 * @brief Echelonne (supérieure) une matrice
 * 
 * @param M_echelonnee la matrice qui recevera la matrice triangulaire semblable
 * @param M la matrice
 */
void matriceEchelonner(matrice *M_echelonnee, matrice *M)
{
    if(!sont_MatricesMemeTaille(M_echelonnee,M))
    {
        puts("Erreur: la matrice qui recoit et la matrice a echelonner n'ont pas la meme taille!");
        return;
    }

    matriceCopier(M,M_echelonnee);

    int i,j;

    for(i = 0; i < M_echelonnee->ligne; i++)
    {
        for(j = 0; j < M_echelonnee->colonne; j++)
        {
            if(i > j)
                eliminationSurLigne(M_echelonnee,i,j); // On élimine chaque coefficient en bas du diagonal
        }
    }
}

/**
 * @brief Calcul le déterminant d'une matrice carrée
 * 
 * @param M la matrice
 * @param det un pointeur qui recevra le déterminant
 * @return true si le déterminant existe
 * @return false sinon
 */
bool matriceDeterminant(matrice *M, CORPS *det)
{
    if(!est_MatriceCarree(M))
    {
        puts("Erreur: la matrice n'est pas carree, le déterminant n'existe pas!");
        return false;
    }

    matrice *E = NULL;
    int i;

    if(!est_MatriceTriangulaireSup(M))
    {
        E = creerMatrice(M->ligne,M->colonne);
        matriceEchelonner(E,M);
    }
    else
        E = M;
    
    for(i = 0, *det = 1; i < E->ligne; i++)
        *det *= E->coefficient[i][i];
    
    if(E!=M) detruireMatrice(E);

    return true;
}

/**
 * @brief Inverse une matrice carrée
 * 
 * @param M_inverse la matrice qui recevra la matrice inverse
 * @param M la matrice à inverser
 */
void matriceInverse(matrice *M_inverse, matrice *M) // Echelonnage réduite à I, voir livre-algebre-1.pdf de exo7.emath.fr, p112-115
{
    if(!est_MatriceInversible(M))
    {
        puts("Erreur: la matrice n'est pas inversible!");
        return;
    }
    if(!sont_MatricesMemeTaille(M_inverse,M))
    {
        puts("Erreur: la matrice qui recoit et la matrice a inverser n'ont pas la meme taille!");
        return;
    }

    matrice *I = NULL;
    I = creerMatrice(M->ligne,M->colonne);
    matriceIdentite(M_inverse);

    matriceCopier(M,I);

    int i,j;
    CORPS lambda;

    // Echelonnage
    for(i = 0; i < I->ligne; i++)
    {
        for(j = 0; j < I->colonne; j++)
        {
            if(i > j && I->coefficient[i][j] != 0)
            {
                if(I->coefficient[j][j] == 0)
                {
                    echangeLigne(I,j,i);
                    echangeLigne(M_inverse,j,i);
                }
                else
                {
                    lambda = -I->coefficient[i][j] / I->coefficient[j][j];
                    combinaisonParAutreLigne(I,lambda,i,j);
                    combinaisonParAutreLigne(M_inverse,lambda,i,j);
                }
            }
        }
    }

    // Echelonnage réduite

        //Homotéties
    for(i = 0; i < I->ligne; i++)
    {
        lambda = 1 / I->coefficient[i][i];
        produitScalaireLigne(I,lambda,i);
        produitScalaireLigne(M_inverse,lambda,i);
    }

        //Eliminations
    for(i = I->ligne-1; i >= 0; i--)
    {
        for(j = I->colonne-1; j >= 0; j--)
        {
            if(i < j && I->coefficient[i][j] != 0)
            {
                if(I->coefficient[j][j] == 0)
                {
                    echangeLigne(I,j,i);
                    echangeLigne(M_inverse,j,i);
                }
                else
                {
                    lambda = -1;
                    combinaisonParAutreLigne(I,lambda,i,j);
                    combinaisonParAutreLigne(M_inverse,lambda,i,j);
                }
            }
        }
    }
    
    detruireMatrice(I);
}
