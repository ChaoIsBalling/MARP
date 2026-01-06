
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include"PriorityQueue.h"
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;
    
    PriorityQueue<int64_t> pq;
    int64_t a;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        pq.push(a);
    }
    int64_t total = 0;
    // resolver el caso posiblemente llamando a otras funciones
    a = pq.top();
    int64_t b = 0;
    pq.pop();
    while (!pq.empty())
    {
        total += a + pq.top();
        b = a + pq.top();
        pq.pop();
        pq.push(b);
        a = pq.top();
        pq.pop();
    }
    // escribir la solución
    cout << total<<"\n";
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
