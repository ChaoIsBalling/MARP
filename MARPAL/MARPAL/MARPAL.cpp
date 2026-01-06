
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include"Matriz.h"
#include"EnterosInf.h"
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

pair<EntInf,EntInf> num_monedas(int i, Matriz<pair<EntInf,EntInf>>& C, const vector<int>&  monedas, const int& Precio, const int& M) {
    if (i == M)return { 10001,101};
    if (C[i][Precio].first != Infinito) return C[i][Precio];
    if (monedas[i] >= Precio) return { monedas[i],1};
    else
    {
        pair<EntInf,EntInf> alt;
        C[i][Precio] = num_monedas(i + 1, C, monedas, Precio - monedas[i], M);
        C[i][Precio].first = C[i][Precio].first + monedas[i];
        C[i][Precio].second = C[i][Precio].second + 1;

        alt = num_monedas(i + 1, C, monedas, Precio, M);

        C[i][Precio] = min(C[i][Precio], alt);
        return C[i][Precio];
    }
}

bool resuelveCaso() {
   
    // leer los datos de la entrada
    int P, N;
    cin >> P >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> monedas;
    int total=0;
     int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        total += n;
        monedas.push_back(n);
    }
    Matriz<pair<EntInf, EntInf>> C(N + 1, total + 1, { Infinito,Infinito });
    vector<int>res(total + 1, 1000000);
    res[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = total; j >= monedas[i]; j--)
        {
            res[j] = min(res[j],res[j-monedas[i]]+1);
        }
    }
    for (int i = P; i <= total; i++)
    {
        if (res[i] != 1000000)
        {
            cout << i << " " << res[i] << endl;
            break;
        }
    }
  
  
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
