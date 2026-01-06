
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

const int MAX = 10000;
const int INF = 1000000000; // ∞
int adyacente(int v, pair<int,int>  mod, int M) {
   
    return (v * mod.first + mod.second) % M;
}
int bfs(int origen, int destino,vector<pair<int,int>>mods,int M) {
    if (origen == destino) return 0;
    vector<int> distancia(MAX, INF);
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 0; i < mods.size(); ++i) {
            int w = adyacente(v, mods[i],M);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
                else cola.push(w);
            }
        }
    }
    return -1;
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int M, S, T;
    cin >> M >> S >> T;
    if (!std::cin)  // fin de la entrada
        return false;

    int n;
    vector<pair<int, int>> mods;
    int v, w;
    cin >> n;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w;
        mods.push_back({ v,w });
    }
    cout << bfs(S, T, mods, M) << endl;
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
