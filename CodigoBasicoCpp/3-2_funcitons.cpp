#include <iostream>
#include <string>
#include <vector>

using namespace std;

// === ENUM ===
enum Estado { OK, ERROR, DESCONOCIDO };

// === STRUCT ===
struct Persona {
    string nombre;
    int edad;
};

// ========== FUNCIONES ==========

// --- int ---
// ✅ Modifica el original
void modificarIntPorReferencia(int& x) {
    x = 123;
}

// ❌ No modifica el original
void modificarIntPorValor(int x) {
    x = 123;
}

// ✅ Modifica el original
void modificarIntPorPuntero(int* x) {
    *x = 123;
}

// --- float ---
void modificarFloat(float& f) {
    f = 9.99f;
}

// --- string (SIEMPRE se pasa por referencia implícita si es array de chars, o explícita si es std::string) ---
// ✅ Modifica el original
void modificarString(string& s) {
    s = "Modificado";
}

void noModificaString(string s) {
    s = "No modifica";
}

// --- ARRAY 1D ---
// ❌ No modifica el original (copiado como puntero, pero no modificamos contenido)
void arrayPorValor(int arr[], int size) {
    // No cambia contenido
    arr = nullptr; // Cambia solo el puntero local
}

// ✅ Modifica el contenido original
void arrayPorReferencia(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 1;
    }
}

// ✅ Modifica el contenido original (por puntero)
void arrayPorPuntero(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// --- ARRAY 2D de tamaño fijo ---
// ✅ Modifica el contenido original
void array2DPorReferencia(int arr[][3], int filas) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j]++;
}

// --- VECTOR 1D ---
// ✅ Modifica el contenido original
void modificarVector(vector<int>& v) {
    for (auto& elem : v)
        elem += 10;
}

// --- VECTOR 2D ---
// ✅ Modifica el contenido original
void modificarVector2D(vector<vector<int>>& m) {
    for (auto& fila : m)
        for (auto& val : fila)
            val++;
}

// --- STRUCT ---
// ❌ No modifica el original
void modificarPersonaValor(Persona p) {
    p.nombre = "Valor";
    p.edad = 0;
}

// ✅ Modifica el original
void modificarPersonaReferencia(Persona& p) {
    p.nombre = "Referencia";
    p.edad = 99;
}

// ✅ Modifica el original
void modificarPersonaPuntero(Persona* p) {
    p->nombre = "Puntero";
    p->edad = 50;
}

// --- CLASS ---
class Auto {
public:
    string marca;
    int año;

    Auto(string m, int a) : marca(m), año(a) {}

    void mostrar() const {
        cout << "Marca: " << marca << ", Año: " << año << endl;
    }

    void cambiarMarca(const string& nueva) {
        marca = nueva;
    }
};

// ========== MAIN ==========

int main() {
    // Básicos
    int entero = 5;
    float flotante = 1.1f;
    double doble = 3.14159;
    string texto = "Texto original";

    modificarIntPorValor(entero); // no cambia
    modificarIntPorReferencia(entero); // cambia
    modificarIntPorPuntero(&entero); // cambia
    modificarFloat(flotante); // cambia
    modificarString(texto); // cambia
    noModificaString(texto); // no cambia

    cout << "--- Tipos básicos ---" << endl;
    cout << "Entero: " << entero << endl;
    cout << "Float: " << flotante << endl;
    cout << "Double: " << doble << endl;
    cout << "String: " << texto << endl << endl;

    // ARRAY 1D
    int arr[5] = {1, 2, 3, 4, 5};
    arrayPorValor(arr, 5);       // no cambia
    arrayPorReferencia(arr, 5);  // suma 1
    arrayPorPuntero(arr, 5);     // multiplica x2

    cout << "--- Array 1D ---" << endl;
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl << endl;

    // ARRAY 2D
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    array2DPorReferencia(matriz, 2);

    cout << "--- Array 2D ---" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // VECTOR
    vector<int> v = {1, 2, 3};
    modificarVector(v);

    cout << "--- Vector 1D ---" << endl;
    for (int n : v) cout << n << " ";
    cout << endl << endl;

    // VECTOR 2D
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    modificarVector2D(mat);

    cout << "--- Vector 2D ---" << endl;
    for (auto fila : mat) {
        for (int val : fila)
            cout << val << " ";
        cout << endl;
    }
    cout << endl;

    // STRUCT
    Persona persona = {"Juan", 30};
    modificarPersonaValor(persona); // no cambia
    modificarPersonaReferencia(persona); // cambia
    modificarPersonaPuntero(&persona); // cambia

    cout << "--- Struct ---" << endl;
    cout << persona.nombre << " - " << persona.edad << endl << endl;

    // ENUM
    Estado estado = OK;
    cout << "--- Enum ---" << endl;
    cout << "Estado (OK=0): " << estado << endl << endl;

    // CLASS
    Auto auto1("Toyota", 2020);
    auto1.mostrar();
    auto1.cambiarMarca("Ford");
    auto1.mostrar();

    return 0;
}