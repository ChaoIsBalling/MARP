
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>

using namespace std;

#include "bintree.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

template <class T>
bool treeResolve(const BinTree<T> tree, int& height, T& menor, T& mayor)
{
    if (tree.empty())
    {
        height = 0;
    }
    else if (tree.right().empty() && tree.left().empty())
    {
        height = 1;
        menor = tree.root();
        mayor = tree.root();
    }
    else if (tree.right().empty())
    {
        int leftHeight;
        T maxIz, minIz;

        bool orden = treeResolve(tree.left(), leftHeight, minIz, maxIz);

        height = leftHeight + 1;
        mayor = max(maxIz, tree.root());
        menor = min(minIz, tree.root());

        if (leftHeight > 1 || maxIz >= tree.root() || !orden)
            return false;
    }  
    else if (tree.left().empty())
    {
        int rightHeight;
        T maxDer, minDer;

        bool orden = treeResolve(tree.right(), rightHeight, minDer, maxDer);

        height = rightHeight + 1;
        mayor = max(maxDer, tree.root());
        menor = min(minDer, tree.root());

        if (rightHeight > 1 || minDer <= tree.root() || !orden)
            return false;
    }
    else
    {
        int leftHeight;
        int rightHeight;

        T menorIz, mayorIz, menorDer, mayorDer;

        bool ordenIz = treeResolve(tree.left(), leftHeight, menorIz, mayorIz);
        bool ordenDer = treeResolve(tree.right(), rightHeight, menorDer, mayorDer);

        height = max(rightHeight, leftHeight) + 1;
        mayor = max(max(mayorIz, mayorDer), tree.root());
        menor = min(min(menorIz, menorDer), tree.root());

        if (abs(leftHeight - rightHeight) > 1 || mayorIz >= tree.root()
            || menorDer <= tree.root() || !ordenDer || !ordenIz)
            return false;
    }

    return true;
}

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    char c;    
    std::cin >> c;
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    bool resuelto= false;
    int height = 0;
    if (c == 'N')
    {
        BinTree<int> t = read_tree<int>(cin);
        int menor;
        int mayor;
        resuelto = treeResolve(t, height, menor, mayor);
    }
    else
    {
        BinTree<string> t = read_tree<string>(cin);
        string menor;
        string mayor;
        resuelto = treeResolve(t, height, menor, mayor);
    }
    // escribir la solución
    if (resuelto)
        cout << "SI\n";
    else
        cout << "NO\n";
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
