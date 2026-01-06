
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<list>
#include<queue>
#include<limits>
#define Camino list;
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include"IndexPQ.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class BFSDirigido {
public:
    BFSDirigido(DigrafoValorado<int64_t> const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }
    bool hayCamino(int v) const {
        return visit[v];
    }
    int distancia(int v) const {
        return dist[v];
    }
    list<int> camino(int v) const {
        if (!hayCamino(v)) throw std::domain_error("No existe camino");
        list<int> cam;
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
    int s;
    void bfs(DigrafoValorado<int64_t> const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto w : g.ady(v)) {
                if (!visit[w.hasta()]) {
                    ant[w.hasta()] = v; dist[w.hasta()] = dist[v] + 1; visit[w.hasta()] = true;
                    q.push(w.hasta());
                }
            }
        }
    }
};
template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()),numAristas(g.V(),0) {
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
    Valor Nums(int v)const { return numAristas[v]; }
    list<AristaDirigida<Valor> > camino(int v) const {
        list<AristaDirigida<Valor> > cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    std::vector<Valor> numAristas;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            numAristas[w] = numAristas[v]+1;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor())
        {
            if (numAristas[w] > numAristas[v] + 1)
            {
                numAristas[w] = numAristas[v] + 1;
            }
        }
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    int C;
    cin >> C;

    DigrafoValorado<int64_t> g1(N);
 
    int v, w, valor;
    for (int i = 0; i < C; i++)
    {
        cin >> v >> w >> valor;
        g1.ponArista({ v - 1,w - 1,valor });
        g1.ponArista({ w - 1,v - 1,valor });
    }
    int K;
    cin >> K;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < K; i++)
    {
        cin >> v >> w;
        Dijkstra<int64_t> a1(g1, v - 1);
        if (a1.hayCamino(w - 1))
        {
            BFSDirigido a2(g1, v - 1);
            cout << a1.distancia(w - 1) << " ";
            if (a1.Nums(w-1) == a2.distancia(w - 1))
                cout << "SI\n";
            else
                cout << "NO\n";
        }
        else
            cout << "SIN CAMINO\n";
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
