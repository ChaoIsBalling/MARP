
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
const int INF = 1000000000;
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int multiplica_matrices(int N) {
    
    Matriz<pair<int, int>> matrices(N , N , { 0,0 });
    for (int i = 0; i < N; i++)
        cin >> matrices[i][i].second;
    for (int d = 1; d < N; ++d) // recorre diagonales
        for (int i = 0; i < N - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            int res= INF;
            for (int k = i; k <= j - 1; ++k) {
                 res =min(res, matrices[i][k].first + matrices[k + 1][j].first) ;
            }
            int pgs = matrices[i][i].second + matrices[i + 1][j].second;
            matrices[i][j] = { res + pgs,pgs };
        }
    return matrices[0][N-1].first;
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >>N;
    if (N == 0)
        return false;

    cout<<multiplica_matrices(N)<<endl;
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
