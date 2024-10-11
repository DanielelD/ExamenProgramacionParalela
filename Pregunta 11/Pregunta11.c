#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10  

int main(int argc, char* argv[]) {
    int rank, size;
    int vector1[N], vector2[N], result[N];
    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 3) {
        if (rank == 0) {
            printf("Este programa requiere exactamente 3 procesos.\n");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        printf("Vector 1: ");
        for (i = 0; i < N; i++) {
            vector1[i] = i + 1;  
            vector2[i] = (i + 1) * 2;  
            printf("%d ", vector1[i]);
        }
        printf("\n");

        printf("Vector 2: ");
        for (i = 0; i < N; i++) {
            printf("%d ", vector2[i]);
        }
        printf("\n");

        for (i = 1; i < N; i += 2) {
            MPI_Send(&vector1[i], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Send(&vector2[i], 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        }
        for (i = 0; i < N; i += 2) {
            MPI_Send(&vector1[i], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
            MPI_Send(&vector2[i], 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        }
        for (i = 1; i < N; i += 2) {
            MPI_Recv(&result[i], 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        for (i = 0; i < N; i += 2) {
            MPI_Recv(&result[i], 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        printf("Resultado de la suma: ");
        for (i = 0; i < N; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    else if (rank == 1) {
        for (i = 1; i < N; i += 2) {
            int v1, v2;
            MPI_Recv(&v1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&v2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int suma = v1 + v2;
            MPI_Send(&suma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    else if (rank == 2) {
        for (i = 0; i < N; i += 2) {
            int v1, v2;
            MPI_Recv(&v1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&v2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            int suma = v1 + v2;
            MPI_Send(&suma, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
