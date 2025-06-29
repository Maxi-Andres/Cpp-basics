#include <iostream>
#include <cmath>

int main() {

    //type conversion

    std::cout << (char) 100; // esto es como C

    double x = 3.99;
    double y = 4;
    double z;

    //z = std::max(x, y);
    //z = std::min(x, y);
    //z = pow(2, 4);
    //z = sqrt(9);
    //z = abs(-3);
    //z = round(x);
    //z = ceil(x);
    //z = floor(x);

    std::cout << z << '\n';

    int a;
    int b;
    int h;

    std::cout << "ingrese el cateto 1: ";
    std::cin >> a;

    std::cout << "ingrese el cateto 2: ";
    std::cin >> b;

    h = sqrt(pow(a,2) + pow(b,2));

    std::cout << "La hipotenusa es: " << h;




    getchar();
    return 0;
}
