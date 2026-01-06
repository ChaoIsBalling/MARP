
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include"ConjuntosDisjuntos.h"

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


const vector<pair<int, int>> dirs = { {1,0},{1,-1},{1,1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1} };
bool resuelveCaso() {

    // leer los datos de la entrada
    int F, C;
    cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    cin.ignore(1);
    vector<string> tab(F);
    ConjuntosDisjuntos manchas(F * C);
    int maximo = 0;
    for (string& linea : tab)
        cin >> linea;

    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (tab[i][j] == '#')
            {
                for (auto dir : dirs)
                {
                    int fi, fj;
                    fi = i + dir.first;
                    fj = j + dir.second;
                    if (fi >= 0 && fi < F && fj >= 0 && fj < C && tab[fi][fj] == '#')
                    {
                        manchas.unir(i * C + j, fi * C + fj);
                    }
                    maximo = max(maximo, manchas.cardinal(i * C + j));
                }
            }
        }
    }
    cout << maximo << " ";

    int n;
    cin >> n;
    int v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> w;
        v = v - 1;
        w = w - 1;
        tab[v][w] = '#';
        for (auto dir : dirs)
        {
            int fi, fj;
            fi = v + dir.first;
            fj = w + dir.second;
            if (fi >= 0 && fi < F && fj >= 0 && fj < C && tab[fi][fj] == '#')
            {
                manchas.unir(v * C + w, fi * C + fj);
            }
            maximo = max(maximo, manchas.cardinal(v * C + w));
           
        }
         cout << maximo << " ";
    }
        cout << endl;
    
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
