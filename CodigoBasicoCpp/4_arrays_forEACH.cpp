#include <iostream>
#include <array> // array especifico
#include <vector> // vector, tamaño dinamico

//! En C++ moderno, std::vector y std::array guardan el tamaño, y se puede acceder con .size().

void imprimir(const std::array<int, 4>& arr) {
    for (int n : arr) std::cout << n << " ";
    std::cout << '\n';
}

void imprimir(const std::vector<int>& v) {
    for (int n : v) std::cout << n << " ";
    std::cout << '\n';
}

void sort(int array[], int size);

int main() {
    
    //* array
    std::string cars[] = {"Corvette", "Mustang", "Ford"};

    std::cout << sizeof(cars) << " bytes \n";

    std::cout << sizeof(cars)/sizeof(std::string) << " elementos \n";

    for(int i = 0; i < sizeof(cars)/sizeof(std::string); i++){ // de esta manera si cambio el array no lo tengo que cambiar
        std::cout << cars[i] << '\n';
    }

    for(std::string car : cars){ //! este for lo permite C++   for(type element : elements)
        std::cout << car << '\n';
    }

    std::array<int, 4> datos = {5, 6, 7, 8};
    imprimir(datos);

    std::vector<int> datos2 = {100, 200, 300};
    imprimir(datos2);

    int numbers[] = {12, 45, 1, 56, 9, 1, 2};
    int numbers_size = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, numbers_size);

    for(int num : numbers){ //! este for lo permite C++   for(type element : elements)
        std::cout << num << '\n';
    }


    std::string foods[150];

    fill(foods, foods + 100, "pizza"); // Rellena desde foods[0] hasta foods[99] (sin incluir foods[100]) con "pizza".

    std::fill(foods + 100, foods + 150, "hamburguesa");

    getchar();
    return 0;
}

void sort(int array[], int size){
    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}