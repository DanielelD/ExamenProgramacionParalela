#include <stdio.h>
void suma(int *a, int *b, int *resultado);
void resta(int *a, int *b, int *resultado);
void multiplicacion(int *a, int *b, int *resultado);
void division(int *a, int *b, float *resultado);
int main() {
    int num1, num2, opcion, resultadoInt;
    float resultadoFloat;
    
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);
    
    printf("Seleccione la operación (1:Suma, 2:Resta, 3:Multiplicación, 4:División): ");
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1:
            suma(&num1, &num2, &resultadoInt);
            printf("Resultado: %d\n", resultadoInt);
            break;
        case 2:
            resta(&num1, &num2, &resultadoInt);
            printf("Resultado: %d\n", resultadoInt);
            break;
        case 3:
            multiplicacion(&num1, &num2, &resultadoInt);
            printf("Resultado: %d\n", resultadoInt);
            break;
        case 4:
            if (num2 != 0) {
                division(&num1, &num2, &resultadoFloat);
                printf("Resultado: %.2f\n", resultadoFloat);
            } else {
                printf("Error: No se puede dividir entre cero\n");
            }
            break;
        default:
            printf("Opción no válida\n");
    }
    
    return 0;
}
void suma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}
void resta(int *a, int *b, int *resultado) {
    *resultado = *a - *b;
}
void multiplicacion(int *a, int *b, int *resultado) {
    *resultado = (*a) * (*b);
}
void division(int *a, int *b, float *resultado) {
    *resultado = (float)(*a) / (*b);
}
