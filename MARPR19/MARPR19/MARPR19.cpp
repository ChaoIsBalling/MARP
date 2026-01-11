
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include"Matriz.h"
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int rec(Matriz<int>&C,const vector<int>& duracion, int i, int j, const int& total)
{
    if (i == duracion.size())
    {
        C[i][j] = max(j, total - j);
        return C[i][j];
    }
    if (C[i][j] != -1)
        return C[i][j];
    else
    {
        C[i][j] = min(rec(C, duracion, i + 1, j + duracion[i], total),
            rec(C, duracion, i + 1, j, total));
        return C[i][j];
    }

}
int Duracion(const vector<int>& actividades, int total)
{
    vector<int> fila(total+1, -1);
    for (int d = 0; d <= total; d++)
        fila[d] = max(d, total - d);

    for (int i = 0; i < actividades.size(); i++)
    {
        for (int d = 0; d <= total - actividades[i]; d++)
        {
            fila[d] = min(fila[d], fila[d + actividades[i]]);
        }
    }
    return fila[0];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> duracion;
    int total = 0;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        total += n;
        duracion.push_back(n);
    }
    cout << Duracion(duracion, total) << endl;

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
