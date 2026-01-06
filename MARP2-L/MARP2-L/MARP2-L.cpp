
/*@ <authors>
 *
 * Jiale He (MARP24)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
// propios o los de las estructuras de datos de clase

/*@ <answer>
En este problema lo que hacemos es simplemente crear un struct de instrumentos con su numero y el numero de partituras
correspondientes, luego en el operador< se redefine para que el instrumento con prioridad mayor sea aquella donde el atril 
sea más lleno (se calcula los atriles dividiendo el numero de musicos de cada instrumento entre el numero de partituras)

Para obtener la solución solo hice un recorrido lineal de p-n siendo p el numero de partituras y n el numero de instrumentos 
suponiendo que todos los instrumentos empiezan con una partitura y simplemente cogiendo el elemento mas prioritario de la
pq, haciendole pop, y dándole una partitura extra.

Coste del algoritmo:O(N)
Coste en espacio: O(N)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct instrumentos
{
    int num;//numero de instrumentos
    int part;//numero de partituras
public:
    int resto() const
    {
        int n = num / part;
        if (num % part > 0)
            n += 1;
        return n;
    }
};
bool operator<(instrumentos a, instrumentos b)
{
    return b.resto() > a.resto();
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int p, n;
    cin >> p >> n;
    if (!std::cin)  // fin de la entrada
        return false;
    priority_queue<instrumentos> inst;
    int a;
    instrumentos b;
    b.part = 1;//empezamos suponiendo que cada instrumento y comienza con una partitura
    for (int i = 0;i < n;i++)
    {
        cin >> a;
        b.num = a;
        inst.push(b);
    }
    for(int i=0;i<(p-n);i++)
    {
        b = inst.top();   
        inst.pop();
        b.part++;
        inst.push(b);
    }
    cout << inst.top().resto() << endl;
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
