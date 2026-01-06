
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include<queue>
#include"Matriz.h"
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

long long int rec(Matriz<int>& C,int i, int j, const int& dado)
{
    if (i > dado||j<0)
        return 0;
    if (C[i][j] != -1)
        return C[i][j];
    if (j == 0)
    {
        return 1;
    }
    else
    {
        C[i][j] = rec(C, i, j - i, dado) + rec(C, i+1, j , dado);
    }
    return C[i][j];
}
void resuelveCaso() {
    int dado, num;

    cin >> dado >> num;
    // leer los datos de la entrada

    Matriz<int>C(dado + 1, num + 1, -1);
    cout << rec(C, 1, num, dado)<<endl;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);;
#endif
    return 0;
}
