
/*@ Jiale>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ Jiale */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
// propios o los de las estructuras de datos de clase

/*@ <answer>

Simplemente creamos un struct que contiene los valores necesarios de cada paciente y ponemos en frente de 
la cola de prioridad el paciente con mayor dolor primero y en caso de tener mismo dolor el que ha esperado mas.

Coste en tiempo O(N)
Coste en espacio adicional O(N)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Paciente
{
    int tiempo;
    int dolor;
    string nombre;
};
bool operator<(Paciente p1, Paciente p2)
{
    return p2.dolor > p1.dolor || (p2.dolor == p1.dolor) && p2.tiempo < p1.tiempo;
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0)
        return false;
    char c;
    priority_queue<Paciente> p;
    Paciente dolido;
    int dolor;
    string nombre;
    for (int i = 0;i < n; i++)
    {
        cin >> c;
        if (c == 'I')
        {
            cin >> nombre;
            cin >> dolor;
            dolido.nombre = nombre;
            dolido.dolor = dolor;
            dolido.tiempo = i;
            p.push(dolido);
        }
        else
        {
            cout << p.top().nombre << endl;
            p.pop();
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << "---" << endl;
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
