
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <list>
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
    int N,M;
    cin >> N>>M;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    list<int> Jugador;
    list <int>Ropa;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        Jugador.push_back(n);
    }
    Jugador.sort();
    for (int i = 0; i < M; i++)
    {
        cin >> n;
        Ropa.push_back(n);
    }
    Ropa.sort();
    int count = 0;
    while (!Jugador.empty() && !Ropa.empty())
    {
        if (Jugador.front() > Ropa.front())
            Ropa.pop_front();
        else if(Jugador.front() ==Ropa.front()||(Ropa.front()-Jugador.front())==1 )
        {
            Jugador.pop_front();
            Ropa.pop_front();
        }
        else
        {
            Jugador.pop_front();
            count++;
        }
    }
    cout << Jugador.size()+count << endl;
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
