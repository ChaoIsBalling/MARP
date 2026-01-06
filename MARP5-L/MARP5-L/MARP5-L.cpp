
/*@ <authors>
 *
 * Jiale He MARP24
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<list>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>
    Modificamos el algoritmo de ciclos dirigidos para que no haga un recorrido for para todas las aristas y que solamente haga
    una dfs que empieza por el vertice 0 y continue hasta que no pueda mas sin parar cuando encuentre un ciclo.
    De esta forma podemos ver si un programa que empienze por 0 puede llegar a un vertice final L y tambien ver si hay ciclos 
    en el grafo.

    Coste en Tiempo: O(V+A) siendo V los vertices y A las aristas
    Coste en Espacio: O(V+A)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class CicloDirigido {
public:
    CicloDirigido(Digrafo const& g) : visit(g.V(), false), ant(g.V()),
        apilado(g.V(), false), hayciclo(false) {
          dfs(g, 0);
    }
    bool hayCiclo() const { return hayciclo; }
    bool hayCamino(int v) const { return visit[v];};
    list<int> const& ciclo() const { return _ciclo; }
private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<int> ant; // ant[v] = vértice anterior en el camino a v
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    list<int> _ciclo; // ciclo dirigido (vacío si no existe)
    bool hayciclo;
    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                // se recupera retrocediendo
                hayciclo = true;
                for (int x = v; x != w; x = ant[x])
                    _ciclo.push_front(x);
                _ciclo.push_front(w); _ciclo.push_front(v);
            }
        }
        apilado[v] = false;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int L;
    cin >> L;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo di(L+1);

    int a;
    char c;

    for (int i = 0; i < L; i++)
    {
        cin >> c;
        if (c == 'A')
        {
            di.ponArista(i, i + 1);
        }
        else if (c == 'J')
        {
            cin >> a;
            di.ponArista(i, a - 1);
        }
        else if (c == 'C')
        {
            cin >> a;
            di.ponArista(i, i + 1);
            di.ponArista(i, a - 1);
        }
    }
    CicloDirigido ciclo(di);

    if (ciclo.hayCiclo() && !ciclo.hayCamino(L))
    {
        cout << "NUNCA\n" ;
    }
    else if (!ciclo.hayCiclo() && ciclo.hayCamino(L))
    {
        cout << "SIEMPRE\n";
    }
    else if (ciclo.hayCiclo() && ciclo.hayCamino(L))
    {
        cout << "A VECES\n";
    }
    else
    {
        cout << "NUNCA\n";
    }
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
