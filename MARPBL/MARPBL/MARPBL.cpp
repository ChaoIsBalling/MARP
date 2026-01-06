
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

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
int patin_rec(vector<string> const& patitos, vector<string> const& patitos2, int i, int j, Matriz<int>& patin) {

    if (i >= patitos.size() || j >= patitos2.size()) return 0;
    if (patin[i][j] != -1)
        return patin[i][j];
    else if (patitos[i] == patitos2[j])
        patin[i][j] = patin_rec(patitos, patitos2, i + 1, j + 1, patin) + 1;
    else
        patin[i][j] = max(patin_rec(patitos, patitos2, i + 1, j, patin),patin_rec(patitos, patitos2, i, j + 1, patin));
    return patin[i][j];

}
void reconstruir(vector<string> const& patitos, vector<string> const& patitos2, Matriz<int> const& patin, int i, int j, vector<string>& sol) {
    if (i >= patitos.size() || j >= patitos2.size()) return;
    else if (patitos[i] == patitos2[j]) {
        sol.push_back(patitos[i]);
        reconstruir(patitos, patitos2, patin, i + 1, j + 1, sol);
    }
    else if (patin[i][j + 1] > patin[i + 1][j])
        reconstruir(patitos, patitos2, patin, i, j + 1, sol);
    else
        reconstruir(patitos, patitos2, patin, i + 1, j, sol);
}
bool resuelveCaso() {

    string name;
    getline(cin, name);
    stringstream ss(name);
    getline(cin, name);
    stringstream ss2(name);
    vector<string> v;
    vector<string>v2;
    string s;
    while (getline(ss, s, ' ')) {

        v.push_back(s);
    }
    while (getline(ss2, s, ' ')) {

        v2.push_back(s);
    }
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    Matriz<int> patindromo(v.size() + 1, v2.size() + 1, -1);
    vector<string> sol;
    patin_rec(v, v2, 0, 0, patindromo);
    reconstruir(v, v2, patindromo, 0,0, sol);
    for (auto a : sol)
        cout << a << " ";
    cout << "\n";
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
