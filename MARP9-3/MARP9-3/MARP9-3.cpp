
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<list>
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

void resuelveCaso() {

    // leer los datos de la entrada
    int N, V;
    cin >> N >> V;
    // resolver el caso posiblemente llamando a otras funciones
    list<int> pilas;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        pilas.push_back(n);
    }
    pilas.sort();
    int count = 0;
    while (pilas.size()>1)
    {
        if (pilas.front() + pilas.back() >= V)
        {
            count++;
            pilas.pop_back();
            pilas.pop_front();
        }
        else
        {
            pilas.pop_front();
        }
    }
    cout << count << endl;
    // escribir la solución
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
