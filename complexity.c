#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lu.h"

#define NMAX 1e4

void complexity_lu(){
    
    printf(">>> LU function complexity measurements\n");
    printf("size\ttime\n");

    for (int i = 1; i <= NMAX; i *= 10) {
        Matrix * A = allocate_matrix(i, i);
        for (int k = 0; k < i; k++) {
            for (int l = 0; l < i; l++) {
                A->a[k][l] = 1.0;
            }
        }
        clock_t start, end;
        start = clock();
        lu(A);
        end = clock();
        double cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;

        printf("%d\t%lf\n", i, cpu_time_used);
        free_matrix(A);
    }
}

void complexity_solve(){
    
    printf(">>> LU function complexity measurements\n");
    printf("size\ttime\n");

    for (int i = 1; i <= NMAX; i *= 10) {
        Matrix * A = allocate_matrix(i, i);
        for (int k = 0; k < i; k++) {
            for (int l = 0; l < i; l++) {
                A->a[k][l] = 1.0;
            }
        }
        clock_t start, end;
        start = clock();
        lu(A);
        end = clock();
        double cpu_time_used = ((double) end - start) / CLOCKS_PER_SEC;

        printf("%d\t%lf\n", i, cpu_time_used);
        free_matrix(A);
    }
}

int main(){

    complexity_lu();
}