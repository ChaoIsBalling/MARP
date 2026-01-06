
/*@ <authors>
 *
 *Jiale He MARP24
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

En este ejercicio lo que he hecho ha sido crear tres variables de tipo CaminoMasCorto los cuales
tienen punto de inicio los mismos puntos que Alex, Lucas y la panaderia y a partir de eso usar un for loop para calcular
el coste de ir a cada una de las intersecciones y sacar el minimo a partir de eso.

El coste seria 3*O(V+E) +O(N) siendo N el numero de intersecciones ya que se hacen 3 BFS

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class CaminoMasCorto
{
public:
    CaminoMasCorto(Grafo const &g, int s) : visit(g.V(), false),
                                            ant(g.V()), dist(g.V()), s(s)
    {
        bfs(g);
    }
    // ¿hay camino del origen a v?
    bool hayCamino(int v) const
    {
        return visit[v];
    }
    // número de aristas entre s y v
    int distancia(int v) const
    {
        return dist[v];
    }
    // devuelve el camino más corto desde el origen a v (si existe)
    list<int> camino(int v) const
    {
        if (!hayCamino(v))
            throw std::domain_error("No existe camino");
        list<int> cam;
        for (int x = v; x != s; x = ant[x])
            cam.push_front(x);
        cam.push_front(s);
        return cam;
    }

private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant;    // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist;   // dist[v] = aristas en el camino s-v más corto
    int s;
    void bfs(Grafo const &g)
    {
        std::queue<int> q;
        dist[s] = 0;
        visit[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : g.ady(v))
            {
                if (!visit[w])
                {
                    ant[w] = v;
                    dist[w] = dist[v] + 1;
                    visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};

bool resuelveCaso()
{

    // leer los datos de la entrada
    int N, C, A, L, P;
    cin >> N >> C >>A>> L >> P;
    if (!std::cin) // fin de la entrada
        return false;
    Grafo caminos(N);
    int n, m;
    for (int i = 0; i < C; i++)
    {
        cin >> n >> m;
        caminos.ponArista(n - 1, m - 1);
    }
    CaminoMasCorto Alex(caminos,A-1);
    CaminoMasCorto Lucas(caminos,L-1);
    CaminoMasCorto Panaderia(caminos,P-1);

    // resolver el caso posiblemente llamando a otras funciones
   int coste= Alex.distancia(0) + Lucas.distancia(0) + Panaderia.distancia(0);
    for(int i=1;i<N;i++)
    {
        coste = min(coste, Alex.distancia(i) + Lucas.distancia(i) + Panaderia.distancia(i));
    }
    // escribir la solución
    cout<<coste<<"\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
