#include <iostream>

class Libro {
public:
    std::string titulo;
    std::string autor;
    int paginas;

    // 🟢 Constructor 1: sin parámetros (por defecto)
    Libro() {
        titulo = "Desconocido";
        autor = "Anonimo";
        paginas = 0;
        std::cout << "Libro creado por defecto\n";
    }

    // 🟡 Constructor 2: solo titulo
    Libro(std::string t) {
        titulo = t;
        autor = "Anonimo";
        paginas = 0;
        std::cout << "Libro creado con titulo\n";
    }

    // 🔵 Constructor 3: titulo + autor + paginas
    Libro(std::string t, std::string a, int p) {
        titulo = t;
        autor = a;
        paginas = p;
        std::cout << "Libro creado con todos los datos\n";
    }

    void mostrarInfo() {
        std::cout << "Titulo: " << titulo << ", Autor: " << autor << ", Paginas: " << paginas << "\n";
    }
};

int main() {
    Libro l1;                                // Usa constructor por defecto
    l1.mostrarInfo();

    Libro l2("C++ Basico");                 // Usa constructor con solo titulo
    l2.mostrarInfo();

    Libro l3("1984", "George Orwell", 328); // Usa constructor completo
    l3.mostrarInfo();

    return 0;
}
