
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<cstring>
#include<algorithm>


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
int64_t tiempoToInt(const string& s)
{
    stringstream ss(s);
    int64_t horas;
    int64_t minutos;
    string word;
    getline(ss, word, ':');
    horas = stoi(word);
    getline(ss, word, ':');
    minutos = stoi(word);

    return horas * 60 + minutos;
}
bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0)
        return false;

    int64_t d, m;
    string hora;
    vector<pair<int64_t, int64_t>> pelis;
   
    for (int i = 0; i < N; i++)
    {
        cin >> d;
        cin >> hora;
        cin >> m;
        pelis.push_back({ d * 24 * 60 + tiempoToInt(hora),m });
  }
    sort(pelis.begin(), pelis.end());
    int cont = 1;
    int64_t fin = pelis[0].first + pelis[0].second;

    for (int i = 1; i < pelis.size(); i++)
    {
        if (pelis[i].first < fin)
        {
            if (pelis[i].first + pelis[i].second < fin)
                fin = pelis[i].first + pelis[i].second;
        }
        if (pelis[i].first >= fin+10)
        {
            fin = pelis[i].first + pelis[i].second;
            cont++;
        }
    }
    cout << cont << endl;

    // leer los datos de la entrada

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

