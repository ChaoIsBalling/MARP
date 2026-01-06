
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
#include<unordered_map>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

Para este algoritmo manejo varias estructuras de datos como un vector de strtucts Conferencia, un vector de conferencias, un vector de conferencias que guarda
el orden original de las conferencias y un vector stack de conferencias.
 Lo que hago es que despues de leer las conferencias copio la información en un segundo vector que mantiene el orden original y luego hago un sort para ordenar las conferencias
 por tiempo de inicio en orden ascendente. Depues creo un stack al que le hago push a la primera conferencias i añado al stack en un vector de stack y en un for, hago un while en
 cada iteración para comprobar de uno en uno si la conferencia se puede hacerse en cada sala disponible y si no se hace en una nueva sala.

 Coste en Tiempo (N^2) siendo N el numero de conferencias
 Coste en Espacio (N) siendo N el numero de conferencias

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct Conferencias {
	int ini;
	int fin;
	int sala;
	int index;
};


class Compare {
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first > b.first) {
			return true;
		}
		return false;
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N == 0)
		return false;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> init;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> fint;
	// resolver el caso posiblemente llamando a otras funciones
	vector<Conferencias> conferencias;
	int ini, fin;

	for (int i = 0; i < N; i++)
	{
		cin >> ini >> fin;
		init.push({ ini,i });
		fint.push({ fin,i });
	}
	unordered_map<int, int> res;
	// escribir la solución

	int sol = 0;

	while (!init.empty())
	{
		if (init.top().first < fint.top().first)
		{
			sol++;
			res[init.top().second] = sol;
			
		}
		else
		{
			res[init.top().second] = res[fint.top().second];
			fint.pop();
		}
		init.pop();
	}

	cout << sol << endl;
	for (int i = 0; i < N; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
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
