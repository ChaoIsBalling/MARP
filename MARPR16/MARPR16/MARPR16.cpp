
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
int patin_rec(vector<int> const& patitos, int i, int j, Matriz<int>& patin) {
    int& res = patin[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j - 1)
        {
            if (patitos[i] == patitos[j] && patitos[i] != 0)
                res = 1;
            else
                res = 0;
        }
        else if (patitos[i] == patitos[j] && patitos[i] != 0)
            res = patin_rec(patitos, i + 1, j - 1, patin) + 1;
        else if (patitos[i] == patitos[i + 1] && patitos[i] != 0)
            res = patin_rec(patitos, i + 2, j, patin) + 1;
        else if (patitos[j] == patitos[j - 1] && patitos[j] != 0)
            res = patin_rec(patitos, i, j - 2, patin) + 1;
        else
            res = max(max(patin_rec(patitos, i + 2, j, patin),
                patin_rec(patitos, i, j - 2, patin)), patin_rec(patitos, i + 1, j - 1, patin));
    }
    return res;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int>biz(N);

    for (int i = 0; i < N; i++)
        cin >> biz[i];

    Matriz<int> patindromo(N, N, -1);

    cout << patin_rec(biz, 0, N - 1, patindromo) << endl;
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
