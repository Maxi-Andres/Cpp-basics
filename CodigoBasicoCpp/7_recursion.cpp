#include <iostream>

// 🌀 Función recursiva para calcular factorial
int factorialRecursivo(int n) {
    std::cout << "Recursivo: n = " << n << std::endl;
    if (n <= 1)
        return 1;
    return n * factorialRecursivo(n - 1);
}

// 🔁 Función iterativa para calcular factorial
int factorialIterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        std::cout << "Iterativo: i = " << i << std::endl;
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;

    std::cout << "Ingrese un numero: ";
    std::cin >> numero;

    std::cout << "\n--- Metodo Recursivo ---\n";
    int resRec = factorialRecursivo(numero);
    std::cout << "Factorial (recursivo): " << resRec << "\n";

    std::cout << "\n--- Metodo Iterativo ---\n";
    int resIt = factorialIterativo(numero);
    std::cout << "Factorial (iterativo): " << resIt << "\n";

    return 0;
}
/*
| Criterio    | Recursivo                           | Iterativo                          |
| ----------- | ----------------------------------- | ---------------------------------- |
| Memoria     | Usa el stack para cada llamada      | Solo una variable en el stack      |
| Legibilidad | Más corta y elegante                | Más controlado y explícito         |
| Rendimiento | Más lento en general (por llamadas) | Más eficiente para grandes valores |
| Riesgo      | Stack overflow si `n` es muy grande | No hay stack overflow              |
*/