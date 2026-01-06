
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

class CicloDirigido {
public:
    CicloDirigido(Grafo const& g) : visit(g.V(), false), ant(g.V()),
        apilado(g.V(), false), con(true) {
        for (int v = 0; v < g.V(); ++v)
            if (!visit[v])
                dfs(g, v);
    }
    bool CON()const { return con; }
private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    bool con;
    void dfs(Grafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!con)
                return;
            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                // se recupera retrocediendo
                list<int>cic;
                for (int x = v; x != w; x = ant[x])
                    cic.push_front(x);
                cic.push_front(w); cic.push_front(v);
                if (cic.size() % 2 == 0)
                    con = false;
            }
        }
        apilado[v] = false;
    }
};
bool resuelveCaso()
{

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin) // fin de la entrada
        return false;
    Grafo g(V);
    int v, w;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    CicloDirigido c(g);

    if (c.CON())
        cout << "SI\n";
    else
        cout << "NO\n";
 
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
