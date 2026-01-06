
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<queue>
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
    int edad, n;
    cin >> edad >> n;
    if (edad==0)
        return false;

    priority_queue<int> min;
    priority_queue<int, vector<int>, greater<int>>max;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    int a;
    for (int i = 0; i < (n*2);i++)
    {
        cin >> a;
        if (a > edad)
            max.push(a);
        else
            min.push(a);

        if (i % 2 == 1)
        {
            if (max.size() > min.size())
            {
                min.push(edad);
                edad = max.top();
                max.pop();
            }
            else if (min.size() > max.size())
            {
                max.push(edad);
                edad = min.top();
                min.pop();
            }
            cout << edad << " ";
        }
    }
    cout << "\n";
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
