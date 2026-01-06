
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
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

long long int resueltoRec(Matriz<long long int>& C,int i,int j, const vector<vector<int>>& tab,int N)
{
    if (i == N||j==N || i < 0 || j < 0)
        return 0;
    else if (C[i][j] != -1)
        return C[i][j];
    else
    {
        int a = tab[j][i]+resueltoRec(C, i - 1, j - 1, tab, N);
        int b = tab[j][i] + resueltoRec(C, i , j - 1, tab, N);
        int c = tab[j][i] + resueltoRec(C, i + 1, j - 1, tab, N);
        C[i][j] = max(max(a, b), c);
        return C[i][j];
    }
}
void Resuelto(const vector<vector<int>>&tab)
{
    int N = tab.size();

    int index = 0;
    int valor = 0;
   Matriz<long long int> C(N + 1, N + 1, -1);
    for (int i = 0; i < N; i++)
    {
        int val = resueltoRec(C, i, N - 1, tab, N);
        if (val > valor)
        {
            valor = val;
            index = i;
        }
    }
    cout  << valor <<" " << index + 1 << endl;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N ;
    if (!std::cin)  // fin de la entrada
        return false;
    int n;
    vector<vector<int>>tab;
    for (int i = 0; i < N; i++)
    {
        vector<int>fil;
        for (int j = 0; j < N; j++)
        {
            cin >> n;
            fil.push_back(n);
        }
        tab.push_back(fil);
    }
    Resuelto(tab);
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
