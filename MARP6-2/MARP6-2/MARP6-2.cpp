
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
 bool dfs(GrafoValorado<int> const& G, int v, int umbral, vector<bool>& visit) {
    visit[v] = true;

    for (auto a : G.ady(v)) {
        if (a.valor() >= umbral) {
            int w = a.otro(v);
            if (!visit[w])
               dfs(G, w, umbral,visit);
        }
    }
    return false;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    GrafoValorado<int> g(V);
    // resolver el caso posiblemente llamando a otras funciones
    int v, w,valor;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({ v - 1,w - 1,valor });
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w>>valor;
        vector<bool> visit(V, false);
        dfs(g, v - 1, valor, visit);
        if (visit[w-1])
        {
            cout << "SI\n";
        }
        else
            cout << "NO\n";

    }
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
