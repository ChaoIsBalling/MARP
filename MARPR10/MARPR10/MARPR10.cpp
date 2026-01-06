
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.


 coste en tiempo: 2*O(N log N) porque primero se insertan todos los numeros a la priority queue y luego en un while hacemos el resto de operaciones. Espacio O(N)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N==0)
        return false;

    priority_queue< long long int, vector<long long int>, greater<long long int >> ult;

    long long int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        ult.push(n);
    }

    long long int total = 0;
    long long int a,b;
    while (!ult.empty())
    {
        a = ult.top();
        ult.pop();
        if (!ult.empty())
        {
            b = ult.top();
            ult.pop();
            total += (a + b);
            ult.push(a + b);
        }
    }
    cout << total << '\n';
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
