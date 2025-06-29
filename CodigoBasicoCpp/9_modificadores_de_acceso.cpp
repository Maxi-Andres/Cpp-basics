#include <iostream>

class Demo {
public:
    int publico; // Se puede acceder desde fuera

    void mostrar() {
        std::cout << "Desde mostrar(): privado = " << privado << ", protegido = " << protegido << "\n";
    }

private:
    int privado; // Solo accesible dentro de esta clase

protected:
    int protegido; // Accesible desde esta clase y sus hijas

public:
    // Constructor para inicializar todo
    Demo(int pub, int priv, int prot) {
        publico = pub;
        privado = priv;
        protegido = prot;
    }
};

// 👶 Clase hija que hereda de Demo
class Hija : public Demo {
public:
    Hija(int pub, int priv, int prot) : Demo(pub, priv, prot) {}

    void accederDesdeHija() {
        // publico ✅
        // privado ❌ (no se puede)
        // protegido ✅
        std::cout << "Desde clase hija: protegido = " << protegido << "\n";
    }
};

int main() {
    Demo obj(1, 2, 3);
    std::cout << "Acceso publico: " << obj.publico << "\n";
    
    // ❌ obj.privado = 5;     // Error: privado no accesible desde fuera
    // ❌ obj.protegido = 5;   // Error: protegido tampoco accesible desde fuera

    obj.mostrar(); // ✅ puede acceder a todo internamente

    Hija hijaObj(10, 20, 30);
    hijaObj.accederDesdeHija(); // ✅ puede acceder a "protegido"

    return 0;
}
