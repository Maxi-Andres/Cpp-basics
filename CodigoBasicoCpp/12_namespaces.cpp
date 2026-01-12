#include <iostream>

// =============================
// NAMESPACES
// =============================
namespace Enteros
{
  int sumar(int a, int b)
  {
    return a + b;
  }
}

namespace Decimales
{
  double sumar(double a, double b)
  {
    return a + b;
  }
}

// =============================
// CLASES
// =============================
class Calculadora
{
public:
  // Método de instancia (requiere objeto)
  int restar(int a, int b)
  {
    return a - b;
  }

  // Método estático (se llama con Clase::)
  static int multiplicar(int a, int b)
  {
    return a * b;
  }
};

// Definición de un método fuera de la clase usando ::
int dividir(int a, int b)
{
  return a / b;
}

int main()
{
  // =============================
  // USANDO namespace con ::
  // =============================
  std::cout << Enteros::sumar(2, 3) << std::endl;
  std::cout << Decimales::sumar(2.5, 4.3) << std::endl;

  // =============================
  // OBJETO + .
  // =============================
  Calculadora calc;
  std::cout << calc.restar(10, 7) << std::endl; // objeto.metodo()

  // =============================
  // MÉTODO ESTÁTICO + ::
  // =============================
  std::cout << Calculadora::multiplicar(3, 4) << std::endl; // clase::metodo()

  return 0;
}
