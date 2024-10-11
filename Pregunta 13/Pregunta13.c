#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define N 6  
#define MAX_LEN 100  
int main(int argc, char* argv[]) {
    int rank, size, i;
    char vector[N][MAX_LEN] = {
        "cadena_0",
        "cadena_1",
        "cadena_2",
        "cadena_3",
        "cadena_4",
        "cadena_5"
    };
    char cadena[MAX_LEN];

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
        for (i = 0; i < N; i += 2) {
            MPI_Send(&vector[i], MAX_LEN, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        }
        for (i = 1; i < N; i += 2) {
            MPI_Send(&vector[i], MAX_LEN, MPI_CHAR, 2, 0, MPI_COMM_WORLD);
        }

    } else if (rank == 1) {
        printf("Procesador 1 (pares):\n");
        for (i = 0; i < N; i += 2) {
            MPI_Recv(&cadena, MAX_LEN, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Posición %d: %s\n", i, cadena);
        }

    } else if (rank == 2) {
        printf("Procesador 2 (impares):\n");
        for (i = 1; i < N; i += 2) {
            MPI_Recv(&cadena, MAX_LEN, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Posición %d: %s\n", i, cadena);
        }
    }

    MPI_Finalize();
    return 0;
}
