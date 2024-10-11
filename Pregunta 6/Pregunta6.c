#include <stdio.h>
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int fib[2] = {0, 1}; 
    int siguiente;
    
    for (int i = 2; i <= n; i++) {
        siguiente = fib[0] + fib[1];  
        fib[0] = fib[1];  
        fib[1] = siguiente; 
    }
    
    return fib[1];
}

int main() {
    int n;
    
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    int resultado = fibonacci(n);
    
    printf("El término Fibonacci número %d es: %d\n", n, resultado);
    
    return 0;
}
