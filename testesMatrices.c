#include "testesMatrices.h"

/**
 * @brief Teste si deux matrices ont même taille
 * 
 * @param M la première matrice
 * @param N l'autre matrice
 * @return true si elles ont la même taille
 * @return false sinon
 */
bool sont_MatricesMemeTaille(matrice *M, matrice *N)
{
    return M->ligne == N->ligne && M->colonne == N->colonne;
}

/**
 * @brief Teste si deux matrices sont égales
 * 
 * @param M la première matrice
 * @param N l'autre matrice
 * @return true si elles sont égales
 * @return false si elles sont différentes
 */
bool sont_MatricesEgales(matrice *M, matrice *N)
{
    if(!sont_MatricesMemeTaille(M,N))
        return false;
    
    int i,j;

    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            if(M->coefficient[i][j] != N->coefficient[i][j])
                return false;
        }
    }

    return true;
}

/**
 * @brief Teste si la matrice est carrée
 * 
 * @param M la matrice à tester
 * @return true si elle est carrée
 * @return false sinon
 */
bool est_MatriceCarree(matrice *M)
{
    return M->colonne == M->ligne;
}

/**
 * @brief Teste si la matrice est nulle
 * 
 * @param M la matrice à tester
 * @return true si elle est nulle
 * @return false sinon
 */
bool est_MatriceNulle(matrice *M)
{
    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            if(M->coefficient[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Teste si la matrice est une matrice identité
 * 
 * @param M la matrice à tester
 * @return true si elle est une matrice identité
 * @return false sinon
 */
bool est_MatriceIdentite(matrice *M)
{
    if(!est_MatriceCarree(M))
        return false;
    
    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; j < M->colonne; j++)
        {
            if(i == j && M->coefficient[i][j] != 1)
                return false;
            else if(M->coefficient[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Teste si la matrice est une matrice triangulaire supérieure
 * 
 * @param M la matrice à tester
 * @return true si elle est une matrice triangulaire supérieure
 * @return false sinon
 */
bool est_MatriceTriangulaireSup(matrice *M)
{    
    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; i > j && j < M->colonne; j++)
        {
            if(M->coefficient[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Teste si la matrice est une matrice triangulaire inférieure
 * 
 * @param M la matrice à tester
 * @return true si elle est une matrice triangulaire inférieure
 * @return false sinon
 */
bool est_MatriceTriangulaireInf(matrice *M)
{    
    int i,j;
    for(i = 0; i < M->ligne; i++)
    {
        for(j = 0; i < j && j < M->colonne; j++)
        {
            if(M->coefficient[i][j] != 0)
                return false;
        }
    }
    return true;
}

/**
 * @brief Teste si la matrice est une matrice triangulaire (supérieure ou inférieure)
 * 
 * @param M la matrice à tester
 * @return true si elle est une matrice triangulaire
 * @return false sinon
 */
bool est_MatriceTriangulaire(matrice *M)
{
    return est_MatriceTriangulaireSup(M) || est_MatriceTriangulaireInf(M);
}

/**
 * @brief Teste si la matrice est une matrice diagonale (triangulaire supérieure et inférieure en même temps)
 * 
 * @param M la matrice à tester
 * @return true si elle est une matrice diagonale
 * @return false sinon
 */
bool est_MatriceDiagonale(matrice *M)
{
    return est_MatriceTriangulaireSup(M) && est_MatriceTriangulaireInf(M);
}
