#include <iostream>

// 🎨 Interface simulada
class Dibujable {
public:
    virtual void dibujar() = 0;
    virtual void rotar() = 0;
};

// 🟥 Clase abstracta
class Figura {
public:
    virtual void calcularArea() = 0; // método obligatorio
    void mover() {
        std::cout << "Moviendo figura...\n";
    }
};

// ⭕ Clase concreta que hereda de ambas
class Circulo : public Figura, public Dibujable {
public:
    void dibujar() override {
        std::cout << "Dibujando círculo\n";
    }

    void rotar() override {
        std::cout << "Rotando círculo\n";
    }

    void calcularArea() override {
        std::cout << "Área del círculo: pi * r^2\n";
    }
};

int main() {
    Circulo c;
    c.dibujar();       // De Dibujable
    c.rotar();         // De Dibujable
    c.calcularArea();  // De Figura
    c.mover();         // De Figura (no virtual)

    return 0;
}
