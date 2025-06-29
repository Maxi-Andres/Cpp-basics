#include <iostream>
#include <vector>

// ayuda a reducir TYPOS
typedef std::vector<std::pair<std::string, int>> pairlist_t;
// esto redefine todo esto                       en esto se pone _t por convencion

typedef std::string text_t; // mas facil

using text_t = std::string; // se hace asi tambien, se usa para templates?? (mas comun hacer esto)

namespace first {
    int x = 1;
}
namespace second {
    int x = 2;
}

int main() {

    //* using namespace first; // esto significa que usa los de first en todo el main
    //* using namespace std; // te permite no usar std:: pero tiene muchos conflictos
    //* using std::cout; //esto permite no repetir tanto, pero es una boludes

    int x = 0;

    std::cout << x; // usa como default el local
    std::cout << first::x; // first

    pairlist_t pairlist;

    text_t name = "Maxi";


    getchar();
    return 0;
}