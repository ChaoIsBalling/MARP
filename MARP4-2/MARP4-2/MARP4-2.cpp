
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<queue>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class CaminosDFS {
private:
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int>colors;
    int V;
    Grafo g;
    int s; // vértice origen
    bool dfs(Grafo const& G, int v,int color) {
        colors[v] = color;
        for (int w : G.ady(v)) {
            if (colors[w] == -1) {
                if (!dfs(g, w, 1 - color))
                    return false;
            }
            else if (colors[w] == color)
                return false;
        }
        return true;
    }
public:
    CaminosDFS(Grafo const& g, int s) : 
        ant(g.V()), s(s),colors(g.V(),-1),V(g.V()),g(g) {
    }
    bool bipartido()
    {
        for (int i = 0; i < V; i++) {
            if (colors[i] == -1) {
                if (!dfs(g, i, 0))
                    return false;
            }
        }
        return true;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(V);
    int v, w;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w;
        g.ponArista(v, w);
    }
    // resolver el caso posiblemente llamando a otras funciones
    CaminosDFS bipartido(g, 0);
    if (bipartido.bipartido())
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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
