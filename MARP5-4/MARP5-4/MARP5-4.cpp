
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
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
class OrdenTopologico {
public:
    // g es DAG
    OrdenTopologico(Digrafo const& g) : visit(g.V(), false) {
        for (int v = 0; v < g.V(); ++v)
            if (!visit[v])
                dfs(g, v);
    }
    // devuelve la ordenación topológica
    std::deque<int> const& orden() const {
        return _orden;
    }
private:
    std::vector<bool> visit;
    std::deque<int> _orden; // ordenación topológica
    void dfs(Digrafo const& g, int v) {
        visit[v] = true;
        for (int w : g.ady(v))
            if (!visit[w])
                dfs(g, w);
        _orden.push_front(v);
    }
};

class CicloDirigido {
public:
    CicloDirigido(Digrafo const& g) : visit(g.V(), false),
        apilado(g.V(), false), hayciclo(false) {
        for (int v = 0; v < g.V(); ++v)
            if (!visit[v])
                dfs(g, v);
    }
    bool hayCiclo() const { return hayciclo; }
    list<int> const& ciclo() const { return _ciclo; }
private:
    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    list<int> _ciclo; // ciclo dirigido (vacío si no existe)
    bool hayciclo;
    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (hayciclo) // si hemos encontrado un ciclo terminamos
                return;
            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                // se recupera retrocediendo
                hayciclo = true;
            }
        }
        apilado[v] = false;
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A;
    cin >> V >> A;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo di(V);
    int v, w;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w;
        di.ponArista(v - 1, w - 1);
    }
    OrdenTopologico o(di);
    // resolver el caso posiblemente llamando a otras funciones
    CicloDirigido c(di);
  
    if (c.hayCiclo())
        cout << "NO";
    else
    {
        cout << "SI ";
        vector<int> ins(V,-1);
        int i = 0;
        for (auto a : o.orden())
        {
            ins[a] = i;
            i++;
        }
        for (auto a : ins)
        {
            if (a != -1)
            {
                cout << a << " ";
            }
        }
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
