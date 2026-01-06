
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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
struct Caja
{
    int num;
    int tiempo;
};
bool operator< (Caja a, Caja b)
{
    return b.tiempo < a.tiempo || (a.tiempo == b.tiempo && b.num < a.num);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C;
    cin >> N >> C;
    if (N==0&&C==0)
        return false;
    priority_queue<Caja> pq;
    Caja caj;
    caj.tiempo = 0;
    int a;
    for (int i = 0;i < N;i++)
    {
        caj.num = i + 1;
        pq.push(caj);
    }
    for (int i = 0;i < C;i++)
    {
        cin >> a;;

        caj = pq.top();
        caj.tiempo += a;
        pq.pop();
        pq.push(caj);
    }
    cout << pq.top().num << endl;
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
