
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
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

long long int total(vector<int>const& longitudes, const int& N, const int& L)
{
    vector<long long int> mat(L+1,0);
    mat[0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = L; j >= longitudes[i]; j--)
        {
            mat[j] += mat[j - longitudes[i]];
        }
    }
    return mat[L];
}
long long int minCuerdas(vector<int>const& longitudes, const int& N, const int& L)
{
    vector<long long int> mat(L + 1, 1000000000);
    mat[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = L; j >= longitudes[i]; j--)
        {
            mat[j] =min( mat[j], mat[j - longitudes[i]] + 1);
        }
    }
    return mat[L];
}
long long int minprecio(vector<int>const& longitudes, vector<int>const& precios, const int& N, const int& L)
{
    vector<long long int> mat(L + 1, 1000000000);
    mat[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = L; j >= longitudes[i]; --j)
        {
            mat[j] = min(mat[j], mat[j - longitudes[i]] + precios[i]);
        }
    }
    return mat[L];
}
bool resuelveCaso() {

    // leer los datos de la entrada
    int N, L;
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    int n, m;
    vector<int> longitudes;
    vector<int> precios;
    for (int i = 0; i < N; i++)
    {
        cin >> n >> m;
        longitudes.push_back(n);
        precios.push_back(m);
    }
    // resolver el caso posiblemente llamando a otras funciones
    long long int t = total(longitudes, N, L);

    if (t > 0)
        cout << t <<"\n";
    else
        cout << "NO\n";
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
