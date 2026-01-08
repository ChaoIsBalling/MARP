
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase


const int INF = 100000000;
const pair<int, int> pairINF = { INF,INF };
/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
pair<int, int >rec(Matriz<pair<int, int>>&C, const vector<int>&potencias, const vector<int>&coste, const int& pMin, const int& pMax, int i,int p)
{
    if (i >= coste.size() || p > pMax)
    {
        return { 100000000 +1, 100000000 +1};
    }
    else if (p >= pMin && p <= pMax)
    {
        return { 0,0 };
    }
    else if (C[i][p] != pairINF)
    {
        return C[i][p];
    }
    else
    {
        int aux = min((pMax - p)/potencias[i] , (pMin - p) + 1/ potencias[i] );
        pair<int, int>parAux = { INF,INF };
        for (int k = 0; k < aux; k++)
        {  
            pair<int, int>parAux2 = rec(C,potencias,coste,pMin,pMax,i,p+potencias[i]*(k+1));
            parAux2.first += coste[i]*(k+1);
            parAux2.second += potencias[i]*(k+1);

            pair<int, int>parAux3 = rec(C, potencias, coste, pMin, pMax, i+1, p + potencias[i]*k);
            parAux3.first += coste[i] * (k);
            parAux3.second += potencias[i] * (k);

            parAux = min(parAux, parAux2);
            parAux = min(parAux, parAux3);
        }
        C[i][p] = parAux;
        return C[i][p];
        
    }
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, pMax, pMin;
    cin >> N >> pMax >> pMin;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> coste(N,0);
    vector<int> potencias(N,0);

    for (int i = 0; i < N; i++)
        cin >> potencias[i];

    for (int i = 0; i < N; i++)
        cin >> coste[i];
    pair<int, int > aux;
    Matriz<pair<int, int>>C(N + 1, pMax + 1,pairINF);
    aux = rec(C, potencias, coste, pMin, pMax, 0,0);
    if (aux.first < INF)
        cout << aux.first << " " << aux.second << "\n";
    else
        cout << "IMPOSIBLE\n";
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
