#include <stdio.h>
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float division(int a, int b);

int main() {
    int num1, num2, opcion;
    
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);
    
    printf("Seleccione la operación (1:Suma, 2:Resta, 3:Multiplicación, 4:División): ");
    scanf("%d", &opcion);
    
    switch(opcion) {
        case 1:
            printf("Resultado: %d\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado: %d\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado: %d\n", multiplicacion(num1, num2));
            break;
        case 4:
            if (num2 != 0)
                printf("Resultado: %.2f\n", division(num1, num2));
            else
                printf("Error: No se puede dividir entre cero\n");
            break;
        default:
            printf("Opción no válida\n");
    }
    
    return 0;
}

int suma(int a, int b) {
    return a + b;
}
int resta(int a, int b) {
    return a - b;
}
int multiplicacion(int a, int b) {
    return a * b;
}
float division(int a, int b) {
    return (float)a / b;
}
