#include <iostream>

// 🔧 Template para encontrar el mayor de dos valores de cualquier tipo
template <typename T>
//template le dice al compilador: "esto es una función o clase genérica"
//  typename T define un tipo genérico llamado T
//  T puede ser reemplazado por int, float, char, etc., según lo que le pases
T maximo(T a, T b) { // T es el datatype
    return (a > b) ? a : b;
}

template <typename U, typename V>
auto max(U a, V b) { // auto devuelve automaticamente el typo correcto
    
}

int main() {
    std::cout << "Máximo entre 4 y 7: " << maximo(4, 7) << std::endl;           // int
    std::cout << "Máximo entre 3.14 y 2.71: " << maximo(3.14, 2.71) << std::endl; // double
    std::cout << "Máximo entre 'a' y 'z': " << maximo('a', 'z') << std::endl;     // char

    return 0;
}
