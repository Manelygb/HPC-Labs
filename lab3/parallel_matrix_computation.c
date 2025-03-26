#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500

int main() {
    int A[N][N], B[N][N], C_serial[N][N] = {0}, C_parallel[N][N] = {0};

    // Initialize matrices A and B with random numbers
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    
    // Serial Matrix Multiplication
    
    double start_serial = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C_serial[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end_serial = omp_get_wtime();
    printf("Serial Time: %f seconds\n", end_serial - start_serial);

    
    // Parallel Matrix Multiplication
    
    double start_parallel = omp_get_wtime();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C_parallel[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end_parallel = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end_parallel - start_parallel);

    
    // Validate Correctness

    int correct = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C_serial[i][j] != C_parallel[i][j]) {
                correct = 0;
                break;
            }
        }
    }

    if (correct)
        printf("Results are correct!\n");
    else
        printf("Results are incorrect!\n");

    
    // Performance Comparison
    
    double speedup = (end_serial - start_serial) / (end_parallel - start_parallel);
    printf("Speedup: %.2fx\n", speedup);

    return 0;
}
