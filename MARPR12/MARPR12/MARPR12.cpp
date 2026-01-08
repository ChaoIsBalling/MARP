
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct Bateria
{
    int turno;
    long long int tiempo;
    long long int restante;

};
bool operator< (Bateria a, Bateria b)
{
    return (a.restante > b.restante) || (a.restante == b.restante && a.turno > b.turno);
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<Bateria>bats;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        bats.push({i+1,n,n});
    }
    int M;
    cin >> M;
    queue<Bateria> repuesto;
    for (int i = 0; i < M; i++)
    {
        cin >> n;
        repuesto.push({N+i+1,n,n});
    }
    int Z, T;
    cin >> Z >> T;
   
    bool done = false;
    while (!bats.empty()&&bats.top().restante<=T)
    {
        Bateria aux = bats.top();
        bats.pop();
        aux.tiempo -= Z;
        if (aux.tiempo > 0)
        {
            aux.restante += aux.tiempo;
            bats.push(aux);
        }
        else if(!repuesto.empty())
        {
            Bateria aux2 = repuesto.front();
            repuesto.pop();
            aux2.restante += aux.restante;
            bats.push(aux2);
        }
    }
    if (bats.empty())
    {
        cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    }
    else
    {
        if (bats.size() != N)
        {
            cout << "FALLO EN EL SISTEMA\n";
        }
        else
        {
            cout << "CORRECTO\n";
        }
        while (!bats.empty())
        {
            cout << bats.top().turno << " " << bats.top().restante << "\n";
            bats.pop();
        }
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
