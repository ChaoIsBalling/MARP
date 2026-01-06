
/*@ <authors>
 *
 * Jiale He MARP24
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool overlap(pair<int, int>a, pair<int, int>b)
{
    if (a.second > b.first)
        return true;
    if (a.second > b.second)
        return true;

    return false;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<pair<int, int>>edificios;
    pair <int, int> lastConnected;
    int ini, fin;
    for (int i = 0; i < N; i++)
    {
        cin >>ini >> fin;
        edificios.push_back({ ini,fin });
    }
    sort(edificios.begin(), edificios.end());
    int count=1;
    lastConnected = edificios[0];
    for (int i = 1; i < N; i++ )
    {
        if (overlap(lastConnected, edificios[i]))
        {
            lastConnected.first = max(lastConnected.first, edificios[i].first);
            lastConnected.second = min(lastConnected.second, edificios[i].second);
        }
        else
        {
            count++;
            lastConnected = edificios[i];
        }
    }
    cout << count << endl;
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
