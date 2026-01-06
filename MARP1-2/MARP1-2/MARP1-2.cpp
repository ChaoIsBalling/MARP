
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;

#include "TreeSet_AVL.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

El coste del algoritmo es logaritmico ya que no recorres todo el arbol. Log(N) siendo N el numero de nodos del arbol.
El algoritmo lo que hace es sumarle 1 al tam_i de cada elemento cuando se le hace una inserción a la izquierda y cuando 
tienes rotaciones derechas o izquierdas se maneja el tam_i de forma respectiva 

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n==0)
        return false;
    int a;
    Set<int>ents;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        ents.insert(a);
    }
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        try {
            cout<<ents.kesimo(a)<<endl;
        }
        catch (exception e)
        {
            cout << "??\n";
        }
    }
    cout << "---" << endl;
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
