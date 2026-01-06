
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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
struct Objeto { int peso; double valor; };
double mochila_rec(vector<Objeto> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0) mochila[i][j] = 0;
    else if (obj[i - 1].peso > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),
            mochila_rec(obj, i - 1, j - obj[i - 1].peso, mochila)
            + obj[i - 1].valor);
    return mochila[i][j];
}
double mochila(vector<Objeto> const& objetos, int M, vector<bool>& sol) {
    int n = objetos.size();
    Matriz<double> mochila(n + 1, M + 1, -1);
    double valor = mochila_rec(objetos, n, M, mochila);
    // cálculo de los objetos
    int i = n, j = M;
    int num=0;
    sol = vector<bool>(n, false);
    while (i > 0 && j > 0) {
        if (mochila[i][j] != mochila[i - 1][j]) {
            sol[i - 1] = true; j = j - objetos[i - 1].peso;
            num++;
        }
        --i;
    }
    cout << valor << endl << num << endl;
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i])
        {
            cout << objetos[i].peso / 3<<" " << objetos[i].valor << endl;
        }
    }
    return valor;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int T, N;
    cin >> T >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<Objeto> cofres;
    int t;
    double n;
    for (int i = 0; i < N; i++)
    {
        cin >> t >> n;
        cofres.push_back({t*3,n});
    }
    // resolver el caso posiblemente llamando a otras funciones
    vector<bool> sol;
    mochila(cofres, T, sol);
    cout << "---\n";

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
