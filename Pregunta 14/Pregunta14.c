#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4  
void imprimir_matriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int rank, size, i, j, k;
    int A[N][N], B[N][N], C[N][N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != N) {
        if (rank == 0) {
            printf("Este programa requiere exactamente %d procesos.\n", N);
        }
        MPI_Finalize();
        return 0;
    }
    if (rank == 0) {
        printf("Matriz A:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                A[i][j] = i + j;  
            }
        }
        imprimir_matriz(A);

        printf("\nMatriz B:\n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                B[i][j] = i * j;  
            }
        }
        imprimir_matriz(B);
    }
    int fila_A[N];
    MPI_Scatter(A, N, MPI_INT, fila_A, N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    int fila_C[N] = {0};  
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fila_C[i] += fila_A[j] * B[j][i];
        }
    }
    MPI_Gather(fila_C, N, MPI_INT, C, N, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("\nMatriz C (resultado de A x B):\n");
        imprimir_matriz(C);
    }

    MPI_Finalize();
    return 0;
}
