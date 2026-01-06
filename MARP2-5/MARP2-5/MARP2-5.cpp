
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#include"PriorityQueue.h"
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
    if (!std::cin)  // fin de la entrada
        return false;
   
    // resolver el caso posiblemente llamando a otras funciones

    int k;
    long int a;
    vector<stack<long int>> comics;
    PriorityQueue<pair<long int, int>> colas;
    long int menor = 100000000;
    for (int i = 0;i < n;i++)
    {
        cin >> k;
        stack<long int> comic;
        comics.push_back(comic);
        for (int j = 0;j < k;j++)
        {
            cin >> a;
            menor = min(a, menor);
            comics[i].push(a);
        }
    }
    for (int i = 0;i < n;i++)
    {
        colas.push({ comics[i].top(),i });
        comics[i].pop();
    }

    // escribir la solución
    bool found=false;
    int count = 1;
    while (!found)
    {
        if (colas.top().first == menor)
            found = true;
        else {
            auto cola = colas.top();
            colas.pop();
            if (!comics[cola.second].empty())
            {
                colas.push({ comics[cola.second].top() ,cola.second });
                comics[cola.second].pop();
            }
            count++;
        }
    }

    cout << count << "\n";
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
