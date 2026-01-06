
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<cmath>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int vacasRec(Matriz<int>&C,const vector<int>&cubos,int i, int j, int N)
{
    if (i == N || j < 0 || i>j)
        return 0;
    else if (C[i][j] != -1)
        return C[i][j];
    else if (i == j)
    {
        C[i][j] = cubos[i];
        return C[i][j];
    }
    else
    {
        int left, right;
        if (cubos[i + 1] > cubos[j])
            left = cubos[i] + vacasRec(C, cubos, i + 2, j, N);
        else
            left = cubos[i] + vacasRec(C, cubos, i + 1, j-1, N);

        if (cubos[i] > cubos[j - 1])
            right = cubos[j] + vacasRec(C, cubos, i + 1, j - 1, N);
        else
            right = cubos[j] + vacasRec(C, cubos, i , j - 2, N);
        C[i][j] = max(left, right);
        return C[i][j];
    }
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N==0)
        return false;

    int n;
    vector<int> cubos;
    int total=0;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        total += n;
        cubos.push_back(n);
    }
    // resolver el caso posiblemente llamando a otras funciones
    if (N == 1)
        cout << n <<"\n";
    else {
        Matriz<int>C(N + 1, N + 1, -1);
        cout << vacasRec(C, cubos, 0, N - 1, N) << '\n';
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
