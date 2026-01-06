
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include"Matriz.h"
#include"EnterosInf.h"
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 En este ejercicio usamos una version modificada del algoritmo de la mochila para resolver el ejercicio, Lo que hacemos es con un for pasar por todos los casos posibles 
 de chorizos para ver cual es el caso que nos da el mayor beneficio.
 
 El coste en tiempo y espacio es de O(N*M) siendo N el numero de objetos y M el peso 
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Objeto { int peso; double valor; int chorizoNecesario; int panNecesario; };

double mochila_rec(vector<Objeto> const& obj, int i, int j,
    Matriz<double>& mochila) {
    if (i == obj.size()||j<0)
        return 0;
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    else if (obj[i].panNecesario > j)
        mochila[i][j] = mochila_rec(obj, i +1, j,mochila);
    else
    {
        int mini = min((obj[i].peso / obj[i].chorizoNecesario), j / obj[i].panNecesario);
        for (int k = 0; k <=mini; k++) {
            mochila[i][j] = max(mochila_rec(obj, i+1, j - obj[i].panNecesario*k, mochila) + obj[i].valor*k,
                mochila[i][j]);
        }
    }
    return mochila[i][j];
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int N, masa;
    cin >>N>>masa;
    if (!std::cin)  // fin de la entrada
        return false;
    int peso, gchorizo, mPan;
    double valor;
    vector<Objeto> bollos;
    for (int i = 0; i < N; i++)
    {
        cin >> peso >> gchorizo >> mPan >> valor;
        bollos.push_back({peso,valor,gchorizo,mPan});
    }

    Matriz<double> mochila (N + 1, masa + 1, -1);
    cout << mochila_rec(bollos, 0, masa, mochila) << endl;
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
