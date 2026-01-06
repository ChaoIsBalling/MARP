
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <limits>
#include"DigrafoValorado.h"
#include"IndexPQ.h"
using namespace std;
template <typename Valor>
using Camino = list<Valor>;// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Rutas
{
    int64_t rutaA;
    int64_t rutaB;
    int index;
};
bool compareInterval(pair<int, int> i1, pair<int, int> i2)
{
    return (i1.first> i2.first);
}

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

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    DigrafoValorado<int64_t> cams(N);

    int v, w, valor;
    for (int i = 0; i < M; i++)
    {
        cin >> v >> w >> valor;
        cams.ponArista({ v - 1,w - 1,valor });
        cams.ponArista({ w - 1,v - 1,valor });
    }

    Dijkstra<int64_t> a(cams, 0);
    Dijkstra<int64_t>b(cams, N - 1);

    vector<pair<int,int>> rutas;

    for (int i = 1; i < N - 1; i++)
    {
        rutas.push_back({ abs(a.distancia(i)-b.distancia(i)),i });
    }

    sort(rutas.begin(), rutas.end(),compareInterval);
    int countA = 0;
    int countB = 0;
    int64_t total=0;
    for (int i = 0; i < rutas.size(); i++)
    {
        if (countA<(N-2)/2&& countB<(N-2)/2)
        {
            if (a.distancia(rutas[i].second) < b.distancia(rutas[i].second))
            {
                total += (a.distancia(rutas[i].second ));
                countA++;
           }
            else
            {
                total += (b.distancia(rutas[i].second ));
                countB++;
            }
       }
        else if (countA < (N - 2) / 2)
        {
            total += (a.distancia(rutas[i].second));
            countA++;
        }
        else if(countB < (N - 2) / 2)
        {
            total += (b.distancia(rutas[i].second));
            countB++;
        }
    }
  
    if (N == 2)
        cout << 0 << endl;
    else
    cout << total*2<< endl;
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
