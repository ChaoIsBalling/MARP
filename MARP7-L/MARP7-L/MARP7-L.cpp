/*@ <authors>
 *
 * MARP43 Luis Javier Navarrete Pulupa
 * MARP24 Jiale He
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <limits>
#include"DigrafoValorado.h"
#include"PriorityQueue.h"
#include"IndexPQ.h"
using namespace std;
template <typename Valor>
using Camino = list<Valor>;
/*@ <answer>

En este algoritmo creamos un primer dijikstra desde la oficina de paqueteria hasta el resto de casas y un segundo Dijikstra al que le metemos
el grafo inverso y luego en un bucle comprobamos por casas si hay camino tanto en el dijikstra normal y en el dijikstra inverso desde la oficina
hacia cada destino y sihay un camino posible hacia ellos sumamos el esfuerzo hacia ese camino tanto del dijikstra normal como el dijikstra inverso

Coste en Tiempo 2*O(A Log V) siendo A el numero de tramos, V el numero de casas
Coste en Espacio 2*O(V) siendo V el numero de casas
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};


bool resuelveCaso() {

    // leemos la entrada
    int N, C;
    cin >> N >> C;
    if (!cin)
        return false;

    DigrafoValorado<int> g(N);

    int v, w, valor;
    for (int i = 0; i < C; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({ v - 1,w - 1,valor });
    }
    int P, M;
    cin >> P >> M;
    int esfuerzo = 0;
    bool imposible = false;

    Dijkstra<int> paqueteria(g, P - 1);
    Dijkstra<int> inverso(g.inverso(), P - 1);
    for (int i=0;i< M;i++)
    {
        cin >> v;
        if (!paqueteria.hayCamino(v - 1) || !inverso.hayCamino(v - 1))
            imposible = true;
        else
        {
            esfuerzo += paqueteria.distancia(v - 1) + inverso.distancia(v - 1);
        }
    }
    if (imposible)
        cout << "Imposible\n";
    else
        cout << esfuerzo << endl;

    // leer el resto del caso y resolverlo




    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    if (!in.is_open())
        cout << "Error: no se ha podido abrir el archivo de entrada." << endl;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}
