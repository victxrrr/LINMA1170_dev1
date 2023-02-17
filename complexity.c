#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lu.h"

#define NMAX 32

int N[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 20, 30, 40, 50, 60, 70, 80, 90,
            100, 200, 300, 400, 500, 600, 700, 800, 900,
            1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};

void complexity_lu(){
    
    printf(">>> LU function complexity measurements\n");
    printf("size\ttime\n");

    int result;
    double cpu_time_used;

    int i;
    for (int n = 0; n < NMAX; n++) {
        do {
            i = N[n];
            Matrix * A = allocate_matrix(i, i);
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < i; l++) {
                    // matrice diagonale strictement dominante pour éviter les pivots nuls
                    if (k == l) {
                        A->a[k][l] = drand48() + 2.0;
                    } else {
                        A->a[k][l] = drand48(); 
                    }  
                }
            }

            clock_t start, end;
            start = clock();
            result = lu(A);
            end = clock();
            cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;

            free_matrix(A);

        } while (result == -1); // si pivot nul, réessayer

        printf("%d\t%lf\n", i, cpu_time_used);
    }
}

void complexity_solve(){
    
    printf(">>> Solve function complexity measurements\n");
    printf("size\ttime\n");

    int result;
    double cpu_time_used;

    int i;
    for (int n = 0; n < NMAX; n++) {
        do {
            i = N[n];
            Matrix * A = allocate_matrix(i, i);
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < i; l++) {
                    // matrice diagonale strictement dominante pour éviter les pivots nuls
                    if (k == l) {
                        A->a[k][l] = drand48() + 2.0;
                    } else {
                        A->a[k][l] = drand48(); 
                    }  
                }
            }
            double *y = (double *) malloc(sizeof(double)*i);
            for (int j = 0; j < 1; j++) {
                y[j] = drand48();
            }
            result = lu(A);
            clock_t start, end;
            start = clock();
            solve(A, y);
            end = clock();
            cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;

            free_matrix(A);
            free(y);

        } while (result == -1);

        printf("%d\t%lf\n", i, cpu_time_used);
    }
}

int main(){

    complexity_lu();
    complexity_solve();

    /*Matrix *L = allocate_matrix(3, 3);
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < k; l++) {
            L->a[k][l] = 10.0*drand48() + 5.0;
        }
        L->a[k][k] = 1.0;
    }

    Matrix *U = allocate_matrix(3, 3);
    for (int k = 0; k < 3; k++) {
        for (int l = k; l < 3; l++) {
            U->a[k][l] = 10.0*drand48() + 5.0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("L%d%d = %f\t", i, j, L->a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("U%d%d = %f\t", i, j, U->a[i][j]);
        }
        printf("\n");
    }*/
}