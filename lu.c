#include <stdio.h>
#include <math.h>
#include "lu.h"


/**
 * Décompose la matrice A en sa factorisation LU : A = L@U
 * @param A: matrice n x n à décomposer
 * @return -1 si l'algorithme rencontre un pivot nul, 0 sinon
*/
int lu(Matrix * A) {

    int n = A->m;

    for (int k = 0; k < n; k++) {
        double akk = A->a[k][k];
        if (fabs(akk) < EPS) return -1;
        for (int i = k + 1; i < n; i++) {
            A->a[i][k] /= akk;
            for (int j = k + 1; j < n; j++) {
                A->a[i][j] -= A->a[i][k]*A->a[k][j];
            }
        }
    }
    return 0;
}

/**
 * Résout LUx = y
 * @param LU: factorisation LU d'une certaine matrice
 * @param y: vecteur modifié contenant la solution x
 * @return 0 si la fonction réussit
*/
int solve(Matrix * LU, double * y){

    int n = LU->m;

    // forward substitution 
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < k; i++) {
            y[k] -= LU->a[k][i]*y[i];
        }
    }

    // backward substitution
    for (int k = n - 1; k >= 0; k--) {
        for (int i = k + 1; i < n; i++) {
            y[k] -= LU->a[k][i]*y[i];
        }
        y[k] /= LU->a[k][k];
    }

    return 0;
}