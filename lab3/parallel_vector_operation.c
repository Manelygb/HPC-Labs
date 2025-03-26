#include <stdio.h>
#include <omp.h>

#define SIZE 100000

int main() {
    int A[SIZE], B[SIZE], C[SIZE];
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = i * 2;
    }

    double start = omp_get_wtime(); // Start timing
    
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    double end = omp_get_wtime(); // End timing
    printf("Time taken: %f seconds\n", end - start);

    return 0;
}
