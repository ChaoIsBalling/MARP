
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class DFSDirigido {
public:
    DFSDirigido(Digrafo const& g, int s) : visit(g.V(), false) {
        dfs(g, s);
    }
    bool alcanzable(int v) const {
        return visit[v];
    }

private:
    std::vector<bool> visit; // visit[v] = ¿hay camino dirigido de s a v?
    int rests = 0;
    void dfs(Digrafo const& g, int v) {
        visit[v] = true;
            for (int w : g.ady(v))
            {
                if (!visit[w])
                {
                    dfs(g, w);
                }
            }
      
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo di(V);
    // resolver el caso posiblemente llamando a otras funciones
    int v, w;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w;
        di.ponArista(v - 1, w - 1);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w;
        DFSDirigido d(di, v - 1);
        DFSDirigido d2(di.inverso(), w - 1);
        if (!d.alcanzable(w - 1))
            cout << "IMPOSIBLE\n";
        else
        {
            int ambos = 0;
            for (int j = 0; j < V; j++)
            {
                if (d.alcanzable(j) && d2.alcanzable(j))
                    ambos++;
            }
            cout << ambos - 2 << endl;
        }
       
    }
    cout << "---\n";
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
