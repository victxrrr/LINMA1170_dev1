#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

void test_allocate_matrix() {
	
	//simple test
	int nrow = 100, ncol = 200;
	Matrix * mat = allocate_matrix(nrow, ncol);
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			mat->a[i][j] = drand48();
		}
	}
	assert(mat->a[12][111] >= 0);
	assert(mat->data[12*200 + 111] == mat->a[12][111]);
	free_matrix(mat);
}

void test_mult_matrix() {

    // simple test
    Matrix * A = allocate_matrix(2,3);
	Matrix * B = allocate_matrix(3,2);
	Matrix * C = allocate_matrix(2,2);
	double ** a = A->a;
	a[0][0] = 1; a[0][1] = 2; a[0][2] = 1;
	a[1][0] = 1; a[1][1] = 1; a[1][2] = 2;

	double ** b = B->a;
	b[0][0] = 2; b[0][1] = 2;
	b[1][0] = 1; b[1][1] = 1;
	b[2][0] = 1; b[2][1] = 2;

	assert(mult_matrix(A,B,C) == 0);
	double **c = C->a;

    double true_c[2][2] = {{5, 6}, {5, 7}};
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			assert(true_c[i][j] == c[i][j]);
		}
	}
	free_matrix(A);
	free_matrix(B);
	free_matrix(C);

	// limit cases tests
	A = allocate_matrix(2, 3);
	B = allocate_matrix(4, 4);
	C = allocate_matrix(2, 4);

	assert(mult_matrix(A, B, C) == -1);

	free_matrix(A);
	free_matrix(B);
	free_matrix(C);

	A = allocate_matrix(2, 4);
	B = allocate_matrix(4, 4);
	C = allocate_matrix(2, 5);

	assert(mult_matrix(A, B, C) == -1);

	free_matrix(A);
	free_matrix(B);
	free_matrix(C);
}

int main(){
	test_allocate_matrix();
	test_mult_matrix();
	return 0;
}