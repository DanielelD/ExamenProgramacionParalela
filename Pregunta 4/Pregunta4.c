#include <stdio.h>

void calcular_pi_iterativo(int *n, double *pi) {
    int i;
    double signo = 1.0;
    *pi = 0.0;
    
    for(i = 0; i < *n; i++) {
        *pi += signo / (2.0 * i + 1.0);
        signo = -signo;  
    }
    
    *pi *= 4.0;  
}

int main() {
    int iteraciones;
    double pi;
    
    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);
    
    calcular_pi_iterativo(&iteraciones, &pi);
    
    printf("El valor aproximado de pi (iterativo) es: %.15f\n", pi);
    
    return 0;
}
