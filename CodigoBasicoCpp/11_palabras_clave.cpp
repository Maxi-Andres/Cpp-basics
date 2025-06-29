#include <iostream>
#include <string>

// class: declara una clase (tipo complejo que agrupa datos y funciones)
class Animal {
protected: // protected: acceso desde esta clase y clases derivadas (herencia)
    std::string nombre;

public: // public: acceso desde cualquier parte del programa
    static int contador;  // static: variable compartida por todos los objetos de la clase

    // constructor (mismo nombre que la clase)
    Animal(std::string n) : nombre(n) {
        contador++;  // aumentar contador cada vez que se crea un objeto Animal
    }

    // virtual: método que puede ser sobrescrito en clases derivadas (polimorfismo)
    // const: no modifica el objeto (no cambia atributos)
    virtual void hablar() const {
        std::cout << nombre << " hace un sonido\n";
    }

    // static: método que pertenece a la clase, no a objetos individuales
    static int obtenerContador() {
        return contador;
    }

    // destructor virtual para asegurar correcta destrucción en herencia
    virtual ~Animal() = default;
};

int Animal::contador = 0; // inicialización de la variable static

// final: impide que esta clase sea heredada
// override: asegura que se sobrescribe un método virtual heredado
// explicit: evita conversiones implícitas con constructores de un solo parámetro
class Perro final : public Animal {
public:
    explicit Perro(std::string n) : Animal(n) {}

    void hablar() const override {
        std::cout << nombre << " dice guau!\n";
    }
};

// mutable: permite modificar esta variable aun dentro de métodos const
class Contador {
private:
    mutable int conteo;

public:
    Contador() : conteo(0) {}

    // método const (no modifica el objeto)
    void incrementar() const {
        conteo++; // mutable permite esto
    }

    int obtener() const {
        return conteo;
    }
};

// friend: permite que una función acceda a miembros privados de una clase
class Caja {
private:
    int secreto;

public:
    Caja(int val) : secreto(val) {}

    friend void mostrarSecreto(const Caja& c);
};

void mostrarSecreto(const Caja& c) {
    std::cout << "El secreto es: " << c.secreto << "\n";
}

// template y typename: para crear clases genéricas (que funcionan con cualquier tipo)
template <typename T>
class Contenedor {
private:
    T valor;

public:
    Contenedor(T v) : valor(v) {}

    T getValor() const {
        return valor;
    }
};

// inline: sugerencia al compilador para reemplazar llamada a función por código (más rápido)
class Calculadora {
public:
    inline int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    Animal a("Animal genérico");
    a.hablar();

    Perro p("Firulais");
    p.hablar();

    Contador c;
    c.incrementar();
    c.incrementar();
    std::cout << "Conteo mutable en método const: " << c.obtener() << "\n";

    Caja caja(42);
    mostrarSecreto(caja);

    Contenedor<int> contInt(123);
    std::cout << "Valor en contenedor: " << contInt.getValor() << "\n";

    Calculadora calc;
    std::cout << "Suma inline: " << calc.sumar(5, 3) << "\n";

    std::cout << "Animales creados: " << Animal::obtenerContador() << "\n";

    return 0;
}
