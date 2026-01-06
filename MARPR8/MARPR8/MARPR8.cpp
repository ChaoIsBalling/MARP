
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
 // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 El coste en tiempo es de O(NLogN) ya que hacemos un bucle en donde en el peor caso vamos haciendo push de la cola de prioridad cada bucle y en espacio de O(N)
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
    int ini, fin;
    // resolver el caso posiblemente llamando a otras funciones
    vector<pair<int, int>> horas;
    for (int i = 0; i < N; i++)
    {
        cin >> ini >> fin;
        horas.push_back({ ini,fin });
    }
    sort(horas.begin(), horas.end());
    priority_queue<int, vector<int>, greater<int>> ult;
    ult.push(horas[0].second);
    int comp = 0;
    for (int i = 1; i < N; i++)
    {
        if (ult.top() <= horas[i].first)
        {
            ult.pop();
            ult.push(horas[i].second);
        }
        else
        {
            comp++;
            ult.push(horas[i].second);
        }
    }
    cout << comp << endl;
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
