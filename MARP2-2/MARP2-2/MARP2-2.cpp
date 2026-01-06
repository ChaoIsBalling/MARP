
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
using namespace std;
#include <queue>  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

    struct User {
        int identificado;
        int periodicidad;
        int periodicidadOG;
    };
    bool operator<(User a, User b)
    {
        return b.periodicidad < a.periodicidad || (b.periodicidad == a.periodicidad && b.identificado < a.identificado);
    }


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n==0)
        return false;

    priority_queue<User> pq;
    int a,b;
   User user;
    for (int i = 0;i < n;i++)
    {
        cin >> a >> b;
        
        user.identificado = a;
        user.periodicidad = b;
        user.periodicidadOG = b;
        pq.push(user);
    }
    cin >> n;
    
    for (int i = 0;i < n;i++)
    {
        cout << pq.top().identificado<< '\n';
        user = pq.top();
        pq.pop();
        user.periodicidad += user.periodicidadOG;
        pq.push(user);
    }

    cout << "---\n";
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
