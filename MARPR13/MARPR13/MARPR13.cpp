
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
pair<int, int>rec(Matriz<pair<int, int>>&C, const vector<int>&potencias, const vector<int>&coste, const int& pMin, const int& pMax, int i,int p)
{
    if (i >= coste.size() || p > pMax)
        return { 100000001 ,100000001};   
    else if (p >= pMin && p <= pMax)   
        return { 0,0 };   
    else if (C[i][p] != pairINF)  
        return C[i][p];
    else
    {
        int aux;
        if ((pMin - p) % potencias[i] == 0)
            aux = (pMin - p) / potencias[i];
        else
            aux = (pMin - p) + 1 / potencias[i];
  
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
pair<int, int> ascendente(const vector<int>& precio, const vector<int>& potencia,const int& maxP, const int& minP)
{
    vector<int>p(maxP + 1, INF);
    p[0] = 0;
    int n =potencia.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = potencia[i - 1]; j <= maxP; j++)
        {
            p[j] = min(p[j],p[j-potencia[i-1]]+precio[i-1]);
        }
    }
    int valor = INF;
    int pot = INF;
    for (int i = minP; i <= maxP; i++)
    {
        if (valor > p[i])
        {
            valor = p[i];
            pot = i;
        }
    }
    return { valor,pot };
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
    aux = ascendente(coste,potencias,pMax,pMin);
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
