
/*@ <authors>
 *
 * Jiale He MARP24
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Compare {
public:
    bool operator()(pair<int, int>a, pair<int, int>b)
    {
     return (a.second )<( b.second);
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int C,F,N;
    cin >>C>>F>> N;
    if (C == 0 && F == 0 && N == 0)
        return false;
    int ini, fin;
    vector<pair<int, int>> trabajos;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> ult;
    for (int i = 0; i < N; i++)
    {
        cin >> ini >> fin;
        trabajos.push_back({ ini,fin });
    }
    sort(trabajos.begin(), trabajos.end());
    int i = 0;
    int count = 0;
    ini = C;
    bool finish = false;
    while (i < N&&!finish)
    {
        if (trabajos[i].first> ini )
        {
            if (ult.empty())
                finish = true;
            else
            {
                ini = ult.top().second;
                ult = priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>();
                count++;

                if (ini >= F)
                    finish = true;  
            }
        } 
        if (trabajos[i].first <= ini && trabajos[i].second > ini)
            ult.push(trabajos[i]);
        i++;
    }
    if (!ult.empty() && !finish)
    {
        ini = ult.top().second;
        count++;
    }

    if (ini < F)
        cout << "Imposible" << endl;
    else
        cout << count << endl;
    
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
