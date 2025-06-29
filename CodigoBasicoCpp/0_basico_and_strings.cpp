#include <iostream>
#include <string>

/*
Función o método	¿Funciona en C++?	    ¿Uso recomendado?
fflush(stdout)	    ✅ Sí	                ✅ Recomendado solo si usás printf
fflush(stdin)	    ⚠️ Depende del sistema	❌ No recomendado
std::cout.flush()	✅ Sí	                ✅ En I/O con cout
std::cin.ignore()	✅ Sí	                ✅ Para limpiar entradas

std::cin.clear() se usa para limpiar los flags de error del flujo de entrada (std::cin) cuando ocurre un error, por ejemplo al ingresar un tipo de dato incorrecto.

Cuando escribís mal un número, como:

    Ingresa un número: hola

    std::cin.fail() se vuelve true ✅
    std::cin entra en modo de error y no acepta más entrada hasta que hagas cin.clear().


*/
int main() {

    std::cout << "i like pizza" << std::endl; // std=standar cout=character out <<=output
    std::cout << "i like pizza" << '\n'; //esto supuestamente es mas performante pero el otro limpia el buffer de output
    
    int x; // declaration
    x = 5; // assignment as always...

    double a = 10.00;
    char b = 'b'; // si o si con '' no con ""
    bool no = false;
    // lo que tiene C aplica

    //! String (objects taht represent a sequense of text)

    std::string name = "Maxi";
    std::cout << "Hello " << name << '\n';

    const double PI = 3.14159264; // esto es como C

    std::string edad;

    std::cout << "Cual es tu edad: ";
    std::cin >> edad; // cin=character input
    


    // esto te sirve para leer string con espacios
    std::getline(std::cin, edad);
    
    std::getline(std::cin >> std::ws, edad); // asi lo que hace es ws=whitespaces elimina new line o espacios

    //! Useful String Methods
    /*Note that std::string data type is mutable meaning that you can change the content of a variable with this data type after initialization*/
    
    std::string userName;
    
    std::cout << "Enter your full name\n";
    std::getline(std::cin, userName);
    
    // get the total numbers of a string using the length function
    std::cout << userName.length() << "\n";
    
    // check is the string is empty or not using the empty method
    std::cout << userName.empty() << "\n";
    
    // delete all the characters in a string using the clear method
    // userName.clear();
    // std::cout << "Result:" << userName;
    
    // concatenate two strings using the append method
    userName.append(" Basdouri"); // userName + " Basdouri"
    std::cout << userName << "\n";
    
    // get a character at a specified index using the [] or the at method
    std::cout << userName[0] << "\n";
    std::cout << userName.at(2) << "\n";
    
    // insert a string starting from a specific index
    userName.insert(userName.length(), " Hello");
    std::cout << userName << "\n";
    
    // find a specific character or string with the find method
    // it returns the index of the first occurence
    std::cout << userName.find("Amine") << "\n";
    
    // delete a portion of string using the erase method
    // it takes the index to start with and how many characters as arguments
    userName.erase(0, 4);
    std::cout << userName << "\n";


    getchar();
    return 0;
}