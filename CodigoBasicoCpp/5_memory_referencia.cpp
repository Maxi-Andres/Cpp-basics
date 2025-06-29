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