
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include"Matriz.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
int rec(vector<int>&C,const vector<int>&sigPos,const vector<int>& beneficios, int i)
{
    if (i == C.size())
        return 0;
    if (C[i] != -1)
        return C[i];
    if (sigPos[i] == -1)
    {   
        C[i] = beneficios[i];
        return C[i];
    }
    else
    {
        for (int j = sigPos[i]; j < C.size(); j++)
        {
            C[i] = max(C[i], beneficios[i] + rec(C, sigPos, beneficios, j));
        }
        return C[i];
    }

}
void  resuelve(const vector<int>& sigPos, const vector<int>& beneficios, const vector<int>& dist)
{
    vector<int> C(beneficios.size(), -1);
    int k = 0;
    int resuelto = 0;
    for (int i = 0; i < beneficios.size(); i++)
    {
        int aux = rec(C, sigPos, beneficios, i);
        if (aux> resuelto)
        {
            resuelto = aux;
            k = i;
        }
        
    }
    cout << resuelto<<":";

    while (k < beneficios.size() && resuelto>0)
    {
        if (C[k] == resuelto)
        {
            cout << " " << dist[k];
            resuelto -= beneficios[k];
            k = sigPos[k];
        }
        else
            k++;
    }
    cout << "\n";
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, S;
    cin >> N >> S;

    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> dist(N,0);
    vector<int>beneficio(N,0);
    for (int i = 0; i < N; i++)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> beneficio[i];
    }
    vector<int> sigPos(N, -1);
    for (int i = 0; i < N; i++)
    {
        int j = i + 1;
        while (j<N&&sigPos[i]==-1)
        {
            if (dist[j] - dist[i] >= S)
                sigPos[i] = j;
            j++;
        }
    }


    resuelve(sigPos, beneficio,dist);
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
