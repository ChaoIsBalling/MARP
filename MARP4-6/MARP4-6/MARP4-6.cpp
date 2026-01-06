
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

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    class MaximaCompConexa {
    public:
        MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0), componentes(g.V()) {
            for (int v = 0; v < g.V(); ++v) {
                if (!visit[v]) { // se recorre una nueva componente conexa
                    int tam = dfs(g, v);
                    tams.push_back(tam);
                }
            }
        }
        // tamaño máximo de una componente conexa
        int tamComp(int v) const {
            return tams[componentes[v]];
        }
    private:
        vector<bool> visit; // visit[v] = se ha visitado el vértice v?
        vector<int> componentes;
        vector<int>tams;
        int maxim; // tamaño de la componente mayor
        int dfs(Grafo const& g, int v) {
            visit[v] = true;
            componentes[v] = tams.size();
            int tam = 1;
            for (int w : g.ady(v)) {
                if (!visit[w])
                    tam += dfs(g, w);
            }
            return tam;
        }
    };
    // leer los datos de la entrada
    int V, N;
    cin >> V >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(V);
    // resolver el caso posiblemente llamando a otras funciones
    int amigo;
    int amigoSig;
    int a;
    for (int i = 0; i < N;i++)
    {
        cin >> a;
        if(a>0)
        cin >> amigo;
        for (int j = 1; j < a; j++)
        {
             cin >> amigoSig;
             g.ponArista(amigo - 1, amigoSig - 1);
             amigo = amigoSig;
            
        }
    }
    MaximaCompConexa maxComp(g);
    for(int i=0;i<V;i++)
    { 
        cout << maxComp.tamComp(i) << " ";
    }
    cout << endl;
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
