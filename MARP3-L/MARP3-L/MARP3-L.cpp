
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase
#include <vector>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
bool compare(pair<int, int> i1, pair<int, int> i2)
{
    return (i1.second > i2.second) || (i1.second == i2.second && i1.first < i2.first);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int D, C, N;
    cin >> D >> C >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<pair<int, int>> canales;
    IndexPQ<int, greater<int>> tele(C);
    int n;
    for (int i = 0; i < C; i++)
    {
        cin >> n;
        tele.push(i, n);
        canales.push_back({ i, 0 });
    }
    int prevtime = 0;
    int time, canal, esp;
    //cout<<tele.top().prioridad<<endl;
    for (int i = 0; i < N; i++)
    {
        cin >> time;
        canales[tele.top().elem].second += (time - prevtime);
        prevtime = time;
        cin >> canal;
        while (canal != -1)
        {
            cin >> esp;
            tele.update(canal - 1, esp);
            cin >> canal;
        }
    }
    canales[tele.top().elem].second += (D - prevtime);

    sort(canales.begin(), canales.end(), compare);

    for (int i = 0; i < C; i++)
    {
        if (canales[i].second != 0)
            cout << canales[i].first + 1 << " " << canales[i].second << endl;
    }

    cout << "---" << endl;

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
