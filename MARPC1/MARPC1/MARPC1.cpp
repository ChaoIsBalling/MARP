
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
int multiplica_matrices(vector<int> const& D) {
    int n = D.size() - 1;
    Matriz<int> matrices(n + 1, n + 1, 0);
    for (int d = 1; d <= n - 1; ++d) // recorre diagonales
        for (int i = 1; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i; k <= j - 1; ++k) {
                int temp = matrices[i][k] + matrices[k + 1][j] +2*( D[j]-D[i - 1]);
                if (temp < matrices[i][j]) { // es mejor partir por k
                    matrices[i][j] = temp; 
                }
            }
        }
    return matrices[1][n];
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int L, N;
    cin >> L >> N;
    if (L==0)
        return false;
    vector<int>lons(N+2);
    lons[0] = 0;
    lons[N + 1] = L;
    for (int i = 1; i <= N; i++)
    {
        cin>>lons[i];
    }
    cout << multiplica_matrices(lons)<<endl;
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
