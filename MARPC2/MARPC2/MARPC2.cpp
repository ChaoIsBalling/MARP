
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<algorithm>
#include"Matriz.h"  
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

struct Pelicula {
    int inicio;
    int fin;
    int duracion;
    bool operator< (const Pelicula& other) {
        return (inicio<other.inicio);
    }
    Pelicula(int ini, int dur) {
        inicio = ini;
        duracion = dur;
        fin = ini + dur + 10;
    }
};
int binSearch(const vector<Pelicula>&pelis,int i, int target)
{
    int j = pelis.size() - 1;
    int mid,sol = -1;
    while (i <= j)
    {    
        mid = (i + j) / 2;
        if (pelis[mid].inicio >= target)
        {
            sol = mid;
            j = mid - 1;
        }
        else
            i = mid + 1;
    }
    return sol;
}
int solucion(const vector<Pelicula>&  pelis,vector<int> &sol, int N, int i)
{
    if (i == N)
        return 0;
    else if (sol[i] != -1)
        return sol[i];
    else
    {
        int sig = binSearch(pelis, i, pelis[i].inicio + pelis[i].duracion+10);
        int aux = pelis[i].duracion;
        if (sig != -1)
            aux += solucion(pelis, sol, N, sig);
        int aux2 = solucion(pelis, sol, N, i+1);
        sol[i] = max(aux, aux2);
        return sol[i];
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N==0)
        return false;
    int d, m,h,dur;
    char aux;
    vector<Pelicula> pelis;

    for (int i = 0; i< N; i++)
    {
        cin >> d;
        cin >> h;
        cin >> aux;
        cin >> m;
        cin >> dur;
        pelis.push_back( Pelicula(d*24*60+h*60+m, dur));
    }
    sort(pelis.begin(), pelis.end());

    vector<int> sol(N, -1);
    // resolver el caso posiblemente llamando a otras funciones
    cout << solucion(pelis, sol, N, 0)<<endl;
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
