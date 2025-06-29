#include <iostream>
#include <string>

// Declaración de funciones
int sumar(int a, int b);                             // Paso por valor
void imprimirMensaje(const std::string& mensaje);    // Paso por referencia constante
void intercambiar(int& x, int& y);                   // Paso por referencia directa
int factorial(int n);                                // Función recursiva
void imprimirArray(int arr[], int size);

// sobrecarga de funciones
void saludar() {
    std::cout << "Hola!" << std::endl;
}
void saludar(std::string nombre) { //! sobrecarga de funciones C no lo permite
    std::cout << "Hola, " << nombre << "!" << std::endl;
}

int main() {
    int num1 = 5, num2 = 10;

    // Función que retorna valor
    int suma = sumar(num1, num2);
    std::cout << "La suma de " << num1 << " y " << num2 << " es: " << suma << '\n';

    // Función void
    imprimirMensaje("¡Hola desde una función void!");

    // Paso por referencia
    std::cout << "Antes de intercambiar: num1 = " << num1 << ", num2 = " << num2 << '\n';
    intercambiar(num1, num2);
    std::cout << "Después de intercambiar: num1 = " << num1 << ", num2 = " << num2 << '\n';

    // Función recursiva
    int numero = 5;
    std::cout << "El factorial de " << numero << " es: " << factorial(numero) << '\n';

    int numeros[] = {10, 20, 30, 40};
    int size = sizeof(numeros) / sizeof(numeros[0]);
    imprimirArray(numeros, size);

    return 0;
}

// Definición de funciones

int sumar(int a, int b) {
    a++; // Se modifica solo la copia local
    return a + b;
}

void imprimirMensaje(const std::string& mensaje) { // const hace que no lo puedas cambiar dentro de la funcion
    std::cout << mensaje << '\n';
}

void intercambiar(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void imprimirArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}