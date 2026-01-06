
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */
#include <iostream>
#include <fstream>
#include<algorithm>
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
int multiplica_matrices(vector<pair<int,int>> const& D,int P, vector<int>& sol) {
    int n = D.size();
    for (int i = 0; i < n ; ++i) // recorre diagonales
        for (int j = P; j>=0;j--) { // recorre elementos de diagonal
            int aux = INF;
            for (int k = 0; k <= D[i].second&&k*D[i].first<=j; ++k) {
                if (sol[j - k * D[i].first] != INF)
                    aux = min(aux, sol[j - k * D[i].first] + k);
            }
            sol[j] = aux;
        }
    return sol[P];
}
int rec(Matriz<int>& C, const vector<pair<int,int>>& monedas, int i,int j,int k)
{
    if (i == monedas.size()||j<0||k==monedas[i].second+1)
        return 100000;
    if (j == 0)
        return 0;
    else
    {
        int aux1 = rec(C, monedas, i, j - monedas[i].first, k + 1) + 1;
        int aux2 = rec(C, monedas,  i + 1, j, 0);
        C[i][j] = min(aux1,aux2);
    }
    return C[i][j];
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;


    vector<pair<int, int>> mon(N);
    int P;
    for (int i = 0; i < N; i++)
        cin >> mon[i].first;
    for (int i = 0; i < N; i++)
        cin >> mon[i].second;
    cin >> P;

    vector<int>sol(P + 1, INF);
    sol[0] = 0;
    multiplica_matrices(mon, P, sol);
    if (sol[P] == INF)
        cout << "NO" << endl;
    else
    cout <<"SI "<< sol[P] << endl;
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
