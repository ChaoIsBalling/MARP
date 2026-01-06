
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
#include<unordered_map>
using namespace std;
 // propios o los de las estructuras de datos de clase

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
int adyacente(int v, int i,const unordered_map<int,int>& tajos) {
    auto it = tajos.find(v + i);
    if (it == tajos.end())
    {
        return v + i;
   }
    return it->second;
}
int bfs(int origen, int destino, int K, const unordered_map<int,int>& tajos) {
    if (origen == destino) return 0;
    vector<int> distancia(destino+1, INF);
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 1; i < K+1; ++i) {
            int w = adyacente(v, i,tajos);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
                else cola.push(w);
            }
        }
    }
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, K, S, E;
    cin >> N >> K >> S >> E;
    if (N==0)
        return false;
    int v, w;
    unordered_map<int, int>tajos;
    for (int i = 0; i < S + E; i++)
    {
        cin >> v >> w;
        tajos[v] = w;
    }
    cout << bfs(1, N * N,K,tajos)<<endl;
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
