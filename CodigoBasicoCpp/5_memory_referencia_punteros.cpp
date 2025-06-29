#include <iostream>

void swap(std::string &x, std::string &y); // le pasas la dirreccion de memoria de la variable y eso es lo qe cambia despues, Se le llama referencia porque se refiere directamente a otra variable existente, sin crear una copia, y sin usar la sintaxis compleja de punteros.

void swap(std::string* x, std::string* y);

int main() {

    std::string name = "maxi";
    int age = 21;
    bool student = true;

    std::cout << name << '\n';
    std::cout << &name << '\n'; // & obtiene la direccion de memoria de la variable (referencia) 

    int a = 10;
    int* ptr = &a;

    std::cout << ptr << '\n';   // Dirección de x
    std::cout << *ptr << '\n';  // Valor de x (10)

    std::string x = "Kool-Aid";
	std::string y = "Water";

	swap(x, y); // ya decis que usas la direccion de memoria cuando declaras la funcion C++

    swap(&x, &y); // Necesitás pasar direcciones para usar punteros 

	std::cout << "X: " << x << '\n';
	std::cout << "Y: " << y << '\n';

    std::cout << "==============" << '\n';

    int numbers[] = {1, 2, 3, 4};

    // int *pNumbers = &numbers; // ❌ Error: &numbers tiene tipo int (*)[4], no se puede asignar a int*
    int *pNumbers = numbers; // ✅ Esto funciona: el array decae a un puntero al primer elemento

    int (*punterovich)[4]; // Asi creo un puntero llamado punterovich de 4 ints

    std::cout << "numbers        = " << numbers << '\n';        // Dirección del primer elemento (&numbers[0])
    std::cout << "*numbers       = " << *numbers << '\n';       // Valor del primer elemento (1)
    std::cout << "numbers[2]     = " << numbers[2] << '\n';     // Valor del tercer elemento (3)
    std::cout << "&numbers       = " << &numbers << '\n';       // Dirección del array completo (tipo int (*)[4])
    std::cout << "&numbers[0]    = " << &numbers[0] << '\n';    // Dirección del primer elemento (igual que numbers)

    std::cout << '\n';

    std::cout << "pNumbers       = " << pNumbers << '\n';       // Dirección del primer elemento (igual que numbers)
    std::cout << "*pNumbers      = " << *pNumbers << '\n';      // Valor del primer elemento (1)
    std::cout << "&pNumbers      = " << &pNumbers << '\n';      // Dirección del puntero pNumbers

    std::cout << '\n';

// Null value = un valor especial que significa que algo no tiene valor.
//              Cuando un puntero contiene un valor nulo, 
//              ese puntero no apunta a ningún lugar (puntero nulo).

//! nullptr = palabra clave que representa un literal de puntero nulo.

// nullptrs son útiles para determinar si una dirección fue asignada exitosamente a un puntero.
// si creas un puntero y no apunta a nada todavia, conviene que apunte a nullptr

    int *pointer = nullptr;
    int x1 = 123;

    pointer = &x1;

    if(pointer == nullptr){
        std::cout << "address was not assigned!\n";
    }
    else{
        std::cout << "address was assigned!\n";
        std::cout << *pointer;
    }

    getchar();
    return 0;
}

void swap(std::string &x, std::string &y){ // si pones const no te deja cambiarlo....
	std::string temp;
	temp = x;
	x = y;
	y = temp;
}

void swap(std::string* x, std::string* y) {
    std::string temp = *x;
    *x = *y;
    *y = temp;
}