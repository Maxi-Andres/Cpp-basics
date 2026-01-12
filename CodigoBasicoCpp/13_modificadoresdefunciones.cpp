#include <iostream>

//////////////////////////////////////////
// 1) static
//  - Pertenece a la clase, no a objetos
//  - No puede usar `this`
//  - Se llama con Clase::funcion()
//////////////////////////////////////////
class DemoStatic
{
public:
  static void mostrar() { std::cout << "static: vivo en la clase\n"; }
};

//////////////////////////////////////////
// 2) virtual
//  - Permite polimorfismo
//  - Indica que se puede sobreescribir en clases hijas
//////////////////////////////////////////
class Base
{
public:
  virtual void saludar() { std::cout << "virtual: soy Base\n"; }
};

//////////////////////////////////////////
// 3) override   (*no es palabra clave de función sola*)
//  - Se usa al redefinir un método virtual en derivadas
//  - El compilador verifica que realmente estamos sobreescribiendo
//////////////////////////////////////////
class Derivada : public Base
{
public:
  void saludar() override { std::cout << "override: soy Derivada\n"; }
};

//////////////////////////////////////////
// 4) final
//  - Evita que un método virtual siga siendo sobreescrito
//////////////////////////////////////////
class Bloqueo : public Base
{
public:
  void saludar() final { std::cout << "final: nadie puede overridear esto\n"; }
};

//////////////////////////////////////////
// 5) inline
//  - Sugiere al compilador insertar el código en lugar de llamarlo
//  - Útil para funciones muy pequeñas
//////////////////////////////////////////
inline int sumar(int a, int b) { return a + b; }

//////////////////////////////////////////
// 6) constexpr
//  - Intenta evaluar la función en tiempo de compilación
//  - Solo funciones puras, sin efectos colaterales
//////////////////////////////////////////
constexpr int cuadrado(int x) { return x * x; }

//////////////////////////////////////////
// 7) const  (*técnicamente no storage specifier, pero super usado*)
//  - No modifica miembros del objeto
//  - Puede usarse en métodos
//////////////////////////////////////////
class DemoConst
{
public:
  void mostrar() const
  {
    std::cout << "const: no puedo modificar atributos de la clase\n";
  }
};

//////////////////////////////////////////
// 8) friend
//  - No es un modificador de función tradicional
//  - Permite que una función externa acceda a privados
//////////////////////////////////////////
class Secreto
{
private:
  int x = 42;

  // Esta función externa puede acceder a `x`
  friend void espiar(const Secreto &);
};

void espiar(const Secreto &s)
{
  std::cout << "friend: el secreto es " << s.x << "\n";
}

int main()
{
  // static
  DemoStatic::mostrar();

  // virtual + override + final
  Base *b1 = new Base();
  Base *b2 = new Derivada();
  Base *b3 = new Bloqueo();

  b1->saludar();
  b2->saludar();
  b3->saludar();

  // inline
  std::cout << "inline sumar: " << sumar(2, 3) << "\n";

  // constexpr
  std::cout << "constexpr cuadrado: " << cuadrado(4) << "\n";

  // const
  DemoConst dc;
  dc.mostrar();

  // friend
  Secreto sec;
  espiar(sec);

  delete b1;
  delete b2;
  delete b3;
  return 0;
}
