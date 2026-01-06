
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int patin_rec(string const& patitos, int i, int j, Matriz<int>& patin) {
    int& res = patin[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 1;
        else if (patitos[i] == patitos[j])
            res = patin_rec(patitos, i + 1, j - 1, patin) + 2;
        else
            res = max(patin_rec(patitos, i + 1, j, patin),
                patin_rec(patitos, i, j - 1, patin));
    }
    return res;
}
void reconstruir(string const& patitos, Matriz<int> const& patin,
    int i, int j, string& sol) {
    if (i > j) return;
    if (i == j) sol.push_back(patitos[i]);
    else if (patitos[i] == patitos[j]) {
        sol.push_back(patitos[i]);
        reconstruir(patitos, patin, i + 1, j - 1, sol);
        sol.push_back(patitos[j]);
    }
    else if (patin[i][j] == patin[i + 1][j])
    {
        sol.push_back(patitos[i]);
        reconstruir(patitos, patin, i + 1, j, sol);
        sol.push_back(patitos[i]);
    }
    else if (patin[i][j] == patin[i][j-1])
    {
        sol.push_back(patitos[j]);
        reconstruir(patitos, patin, i , j-1, sol);
        sol.push_back(patitos[j]);
    }
    else
        reconstruir(patitos, patin, i, j - 1, sol);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    string patitos;
    cin >> patitos;
    if (!std::cin)  // fin de la entrada
        return false;

   int n = patitos.length();
   string sol;
   Matriz<int> patindromo(n, n, -1);
   patin_rec(patitos, 0, n - 1, patindromo);
   reconstruir(patitos, patindromo, 0, n - 1, sol);
   cout << sol.length()-n<<" "<<sol  << '\n';
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
