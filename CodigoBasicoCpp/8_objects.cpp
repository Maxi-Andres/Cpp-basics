#include <iostream>

class Human {
public:
    std::string name;
    std::string occupation;
    int age;

    void eat() {
        std::cout << name << " is eating\n";
    }

    void sleep() {
        std::cout << name << " is sleeping\n";
    }
};

class Animal {
public:
    std::string species;
    int legs;

    // 👇 Constructor por defecto //! MISMO NOMBRE QUE LA CLASE SIEMPRE
    Animal() {
        species = "Unknown";
        legs = 0;
        std::cout << "Animal creado por defecto\n";
    }

    // 👇 Constructor con parámetros
    Animal(std::string sp, int l) {
        species = sp;
        legs = l;
        std::cout << "Animal creado: " << species << " con " << legs << " patas\n";
    }

    //Animal(std::string species, int legs) { // asi this-> es si tenes el mismo nombre en el constructor que los parametros
    //    this->species = species;
    //    this->legs = legs;
    //}

    void makeSound() {
        std::cout << species << " hace un sonido\n";
    }
};

class Car {
private:
    std::string brand;
    int year;

public:
    void setBrand(std::string b) { // setter
        brand = b;
    }

    std::string getBrand() { // getter
        return brand;
    }

    void setYear(int y) { // setter
        if (y > 1885)  // año del primer auto
            year = y;
        else
            year = 0;
    }

    int getYear() { // getter
        return year;
    }

    void showInfo() { 
        std::cout << "Marca: " << brand << ", Año: " << year << "\n";
    }
};

int main() {
    Human human1;

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 70;

    human1.eat(); // Rick is eating

    Human human2 = {"Morty", "student", 14}; // esto es como los structs, se asigna en orden
    human2.sleep(); // Morty is sleeping

// Constructor ===================================

    // Constructor por defecto
    Animal a1;
    a1.makeSound();

    // Constructor con parámetros
    Animal a2("Dog", 4);
    a2.makeSound();

    // ====================== Car ======================
    Car car1;
    car1.setBrand("Toyota");
    car1.setYear(2020);

    std::cout << "Marca del auto: " << car1.getBrand() << "\n";
    std::cout << "Año del auto: " << car1.getYear() << "\n";
    car1.showInfo();

    return 0;
}
