
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <list>
using namespace std; // propios o los de las estructuras de datos de clase

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
    int V, N;
    cin >> V >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    list<int> pesos;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        pesos.push_back(n);
    }
    pesos.sort();
    int count = 0;
    while (pesos.size() > 1)
    {
        if (pesos.front() + pesos.back() <= V)
        {
            pesos.pop_back();
            pesos.pop_front();
            count++;
        }
        else {
            pesos.pop_back();
            count++;
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << count + pesos.size() << endl;
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
