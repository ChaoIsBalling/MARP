
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El coste es de O(V+E) en espacio y tiempo siendo V el numero de animogs y E el numero de conecciones entres amigos
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class MaximaCompConexa {
public:
    MaximaCompConexa(Grafo const& g,vector<int>mons) : visit(g.V(), false), maxim(0),m(mons) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v]) { // se recorre una nueva componente conexa
                int tam = dfs(g, v);
                maxim +=tam;
            }
        }
    }
    // tamaño máximo de una componente conexa
    int maximo() const {
        return maxim;
    }private:
        vector<bool> visit; // visit[v] = se ha visitado el vértice v?
        vector<int>m;
        int maxim; // tamaño de la componente mayor
        int dfs(Grafo const& g, int v) {
            visit[v] = true;
            int tam = m[v];
            for (int w : g.ady(v)) {
                if (!visit[w])
                    tam =min( dfs(g, w),tam);
            }
            return tam;
        }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo amigos(N);
    vector<int>mons(N,0);
    for (int i = 0; i < N; i++)
    {
        cin >> mons[i];
    }

    int v, w;
    for (int i = 0; i < M; ++i) {
        cin >> v >> w;
        amigos.ponArista(v - 1, w - 1);
    }
    MaximaCompConexa mcc(amigos,mons);
    cout << mcc.maximo() << '\n';
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
