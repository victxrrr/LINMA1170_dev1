#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "matrix.h"


/**
 * Alloue une matrice de dimension m x n
 * @param m: nombre de lignes
 * @param n: nombre de colonnes
 * @return pointeur vers une nouvelle structure de données allouée Matrix
*/
Matrix * allocate_matrix(int m, int n) {
	Matrix *mat = (Matrix *) malloc(sizeof(Matrix));
	if (mat == NULL) {
		strerror(errno);
	}
	mat->m = m; mat->n = n;

	double *data = (double *) malloc(sizeof(double)*m*n);
	double **a = (double **) malloc(sizeof(double *)*m);
	if (data == NULL || a == NULL) {
		strerror(errno);
	}
	for (int i = 0; i < m; i++) *(a + i) = data + i*n;
	mat->data = data;
	mat->a = a;
	return mat;
}

/**
 * Libère du heap une structure Matrix précédemment allouée
 * @param mat: structure à libérer
*/
void free_matrix(Matrix * mat) {
	free(mat->a);
	free(mat->data);
	free(mat);
}

/**
 * Fonction auxiliaire calculant le produit matriciel C = A@B
 * @param A: matrice de dimension m x p
 * @param B: matrice de dimension p x n
 * @param C: matrice de dimension m x n
 * @return -1 si les dimensions sont incompatibles, 0 sinon
*/
int mult_matrix(Matrix * A, Matrix * B, Matrix * C) {
	int m = A->m, p = A->n, n = B->n;
    if (B->m != p) return -1;
    if (C->m != m || C->n != n) return -1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C->data[i * n + j] = 0.0;
			for (int k = 0; k < p; k++) {
				C->data[i * n + j] += A->a[i][k] * B->a[k][j];
			}
		}
	}
	return 0;
}

/**
 * Fonction auxiliaire imprimant le contenu de la matrice A sur la sortie standard
 * @param A: matrice de dimension m x n
*/
void print_matrix(Matrix * A) {

	for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < A->n; j++) {
            printf("%.5f\t", A->a[i][j]);
        }
        printf("\n");
    }
}
