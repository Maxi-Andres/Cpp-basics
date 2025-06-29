#include <iostream>

int main() {
    // 🧠 STACK: la variable pNum está en el stack
    int *pNum = nullptr;      // Puntero a entero inicializado con nullptr (C++ moderno)

    // 💾 HEAP: se reserva memoria dinámica para un entero
    pNum = new int;           // Se reserva memoria dinámica para un entero
    *pNum = 21;               // Se asigna valor

    delete pNum;              // Se libera la memoria reservada para el entero

    char *pGrades = NULL;     // Puntero a char (arreglo), en este caso se usa NULL (válido también asi se hace en C)

    pGrades = new char[5];    // Se reserva memoria para un arreglo de 5 caracteres

    delete[] pGrades;         // ✅ Correcto: se libera un arreglo con delete[]

    getchar();                // Espera que se presione una tecla (solo útil si ejecutás en consola de Windows)
    return 0;
}
