
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
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
int ascendente(vector<string>& calle)
{
    int N = calle.size();
    int M = calle[0].size();

    Matriz<int> C(N + 1, M + 1, 0);

    if (calle[0][0] == '.')
        C[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (calle[i][j] == 'X')
                C[i][j] = 0;
            else
            {
                if (i > 0)
                    C[i][j] += C[i - 1][j];
                if (j > 0)
                    C[i][j] += C[i][j - 1];
            }
        }
    }
    return C[N-1][M-1];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;
    string calle;
    vector<string> ciudad;
    for (int i = 0; i < N; i++)
    {
        cin >> calle;
        ciudad.push_back(calle);
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    cout << ascendente(ciudad)<<endl;
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
