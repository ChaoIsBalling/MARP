
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include"ConjuntosDisjuntos.h"
#include"PriorityQueue.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se modifica e lalgoritmo de Kruskal para qe en lugar de guardar el coste total solo guarde el coste de la arista con mayor valor del arbol.
 Luego se hace una comprobación si se trata de un arbol unido o no comprobando los cardinales.

 coste en tiempo 0(AlogV) y coste en espacio O(A+V) siendo V lo pueblos y A las carreteras
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    bool unido;
public:
    Valor costeARM() const {
        return coste;
    }
    bool Unido()const {
        return unido;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste =max(coste,a.valor());
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        unido= cjtos.cardinal(0) ==g.V();
    }
};
void resuelveCaso() {
    int V, A;
    cin >> V >> A;

    GrafoValorado<int>g(V);
    // resolver el caso posiblemente llamando a otras funciones
    int v, w, valor;
    for (int i = 0; i < A; i++)
    {
        cin >> v >> w >> valor;
        g.ponArista({ v - 1,w - 1,valor });
    }
    ARM_Kruskal<int> a(g);
    if (a.Unido())
        cout << a.costeARM() << endl;
    else
        cout << "Imposible\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);;
#endif
    return 0;
}
