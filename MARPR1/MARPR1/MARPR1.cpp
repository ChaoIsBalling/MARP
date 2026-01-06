
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<deque>
#include<list>
#include<limits>
#include<climits>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include"ConjuntosDisjuntos.h"
#include"PriorityQueue.h"
#include "IndexPQ.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Para este algoritmo se ha modificado el metodo relajar del algoritmo de dijikstra  para que en lugar de actualizar
 la pq cuando se encuentra un camino mas corto, se actualiza cuando se enuentra un camino el que requiera de menos 
 capacidad de respiracion

 El coste del alogritmo es de 0(AlogV) y el coste en espacio adicional es de 0(V)
siendo V el numero de camaras en la mina y A el numero de galerias
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
    pq(g.V()),maxDist(g.V(),INF) {
        maxDist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }bool hayCamino(int v) const { return maxDist[v] != INF; }
    Valor distancia(int v) const { return maxDist[v]; }


    private:
        const Valor INF = std::numeric_limits<Valor>::max();
        int origen;
        vector<Valor> maxDist;
        IndexPQ<Valor> pq;
        void relajar(AristaDirigida<Valor> a) {
            int v = a.desde(), w = a.hasta();
            long long int valMax = max(a.valor(), maxDist[v]);
            if (v == origen)
            {
                maxDist[w] = a.valor();
                pq.update(w, maxDist[w]);
            }
            else if (maxDist[w] > valMax)
            {
                maxDist[w] = valMax;
                pq.update(w, maxDist[w]);
            }
        }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A ;
    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int>g(V);
    // resolver el caso posiblemente llamando a otras funciones
    int v, w, valor;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({ v - 1,w - 1,valor });
        g.ponArista({ w - 1,v - 1,valor });
    }
    cin >> v >> w;
    Dijkstra<int> sol(g,v-1);
    if (sol.hayCamino(w-1))
        cout << sol.distancia(w - 1) << endl;
    else
        cout << "IMPOSIBLE\n";
    

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
