
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

 /*@ <authors>
  *
  * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
  *
  *@ </authors> */


#include <iostream>
#include <fstream>
#include<vector>
#include<queue>
#include"Matriz.h"
using namespace std;
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 El coste es de O(n*m) siendo n el numero de filas y m el numero de columnas
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
long long int rec(Matriz<int>& C, int i, int j, vector<vector<int>> tab)
{
    if (i >=tab.size() || j >= tab[0].size())
        return 0;
    if (C[i][j] != -1)
        return C[i][j];
    if (i== tab.size()-1&&j== tab[0].size()-1)
    {
        return 1;
    }
    else
    {
        C[i][j] = rec(C, i+tab[i][j], j, tab) + rec(C, i, j+tab[i][j], tab);
    }
    return C[i][j];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin>>n>>m;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<vector<int>>tab(n,vector<int>(m,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
        }
    }
    Matriz<int>C(n + 1, m + 1, -1);
    cout << rec(C, 0, 0, tab) << endl;
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