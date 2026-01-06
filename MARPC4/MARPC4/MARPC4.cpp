
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
long long int rec(vector<long long int>&C, const int& F, int j)
{
    if (j < 0)
        return 0;
    if (j == 0)
        return 1;
    if (C[j] != -1)
        return C[j] % 1000000007;
    else
    {
       long long int aux = 0;
        for (int i = 1; i <= F + 1; i++)
            aux += rec(C, F, j - i) % 1000000007;
        C[j] = aux % 1000000007;
        return C[j];
    }
}
long long int total(int F, const int& L)
{
    vector<long long int> mat(L + 1, 1);
    for (int i = 2; i <= (F+1); i++)
    {
        int aux = L / i;
        for (int k = 0; k <aux; k++)
        {
            for (int j = L; j >= i; j--)
            {
                mat[j] += mat[j - (i)];
            }
        }
    }
    return mat[L];
}
int multiplica_matrices(vector<int> const& D) {
    int n = D.size() - 1;
    Matriz<int> matrices(n + 1, n + 1, 0);
    for (int d = 1; d <= n - 1; ++d) // recorre diagonales
        for (int i = 1; i <= n - d; ++i) { // recorre elementos de diagonal
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i; k <= j - 1; ++k) {
                int temp = matrices[i][k] + matrices[k + 1][j] + 2 * (D[j] - D[i - 1]);
                if (temp < matrices[i][j]) { // es mejor partir por k
                    matrices[i][j] = temp;
                }
            }
        }
    return matrices[1][n];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int P, F;
    cin >> P >> F;
    if (P==0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    vector<long long int> sol(P+1, -1);
    cout << rec(sol,F,P-1)%1000000007 <<endl;
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
