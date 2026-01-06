
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <unordered_map>
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
const int INF = 1000000000;

class BusquedaAnchura
{
public:
    BusquedaAnchura(Grafo const& g, int s) :visit(g.V(), false),
        ant(g.V()), dist(g.V(), INF), s(s) {
        bfs(g);
    }
    int distancia(int v) const {
        return dist[v];
    }

private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist;
    int s;
    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V,E;
    cin >> V >> E;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(V);
    unordered_map<string, int> nombres;
    string s;
    int v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> s;
        nombres.insert({s,nombres.size()});
        v = nombres[s];
        cin >> s;
        nombres.insert({ s,nombres.size() });
        w = nombres[s];
        g.ponArista(v, w);
    }
    bool connected = true;
    int i = 0;
    int grado = 0;
    while (connected&&i<V-1)
    {
        BusquedaAnchura b(g, i);
        int j = i + 1;
        while( j < V && connected)
        {
            grado = max(grado, b.distancia(j));       
            if (grado == INF)
                connected = false;
            j++;
        }
        i++;
    }
    if (connected)
        cout << grado << '\n';
    else
        cout << "DESCONECTADA\n";
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
