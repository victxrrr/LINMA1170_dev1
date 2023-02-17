#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lu.h"


void test_lu_function(){

    //  2 -1  0
    // -1  2 -1
    //  0 -1  2

    Matrix * A = allocate_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) A->a[i][j] = 2.0;
            else if (i + j == 2) A->a[i][j] = 0.0;
            else A->a[i][j] = -1.0;
        }
    }

    assert(lu(A) == 0);

    double true_lu[3][3] = {{2.0, -1.0, 0.0}, {-0.5, 1.5, -1.0}, {0.0, -2.0/3.0, 4.0/3.0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert(abs(A->a[i][j] - true_lu[i][j]) < 1e-9);
        }
    }

    Matrix *L = allocate_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            L->a[i][j] = A->a[i][j];
        }
        L->a[i][i] = 1.0;
    }

    Matrix *U = allocate_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            U->a[i][j] = A->a[i][j];
        }
    }

    mult_matrix(L, U, A);
    double true_A[3][3] = {{2.0, -1.0, 0.0}, {-1.0, 2.0, -1.0}, {0.0, -1.0, 2.0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert(abs(A->a[i][j] - true_A[i][j]) < 1e-9);
        }
    }
    free_matrix(L);
    free_matrix(U);
    free_matrix(A);


    // pas de rang plein

    Matrix * B = allocate_matrix(3, 3);
    B->a[0][0] = 1.0;
    B->a[0][1] = 2.0;
    B->a[0][2] = 1.0;
    B->a[1][0] = -2.0;
    B->a[1][1] = -3.0;
    B->a[1][2] = 1.0;
    B->a[2][0] = 3.0;
    B->a[2][1] = 5.0;
    B->a[2][2] = 0.0;

    assert(lu(B) == -1);
    free_matrix(B);
}

void test_solve(){

    //  2 -1  0
    // -1  2 -1
    //  0 -1  2

    Matrix * A = allocate_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) A->a[i][j] = 2.0;
            else if (i + j == 2) A->a[i][j] = 0.0;
            else A->a[i][j] = -1.0;
        }
    }

    lu(A);
    double *y = (double *) malloc(sizeof(double)*3);
    *y = 7.0;
    *(y + 1) = 5.0;
    *(y + 2) = 6.0;

    assert(solve(A, y) == 0);
    double true_sol[3] = {37.0/4.0, 23.0/2.0, 35.0/4.0};

    for (int i = 0; i < 3; i++) {
        assert(abs(y[i] - true_sol[i]) < 1e-9);
    }
    free(y);
    free_matrix(A);
}

int main(){
    
    test_lu_function();
    test_solve();

    return 0;
}