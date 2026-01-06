
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
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
struct Drone
{
	int32_t PilaA;
	int32_t PilaB;
};
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, A, B;
	cin >> N >> A >> B;
	if (!std::cin)  // fin de la entrada
		return false;

	priority_queue<int32_t> pilasA;
	priority_queue<int32_t> pilasB;
	vector<Drone> drones;

	int32_t a;
	for (int i = 0; i < A; i++)
	{
		cin >> a;
		pilasA.push(a);
	}
	for (int i = 0; i < B; i++)
	{
		cin >> a;
		pilasB.push(a);
	}
	Drone drone;
	for (int i = 0; i < N; i++)
	{
		drones.push_back(drone);
	}
	// resolver el caso posiblemente llamando a otras funciones
	
	int32_t tiempo;
	while (!pilasA.empty() && !pilasB.empty())
	{
		tiempo = 0;
		int i = 0;
		while (!pilasA.empty() && !pilasB.empty() && i < drones.size())
		{
			drones[i].PilaA = pilasA.top();
			drones[i].PilaB = pilasB.top();
			pilasA.pop();
			pilasB.pop();
			tiempo += min(drones[i].PilaA, drones[i].PilaB);
			i++;
		}

		cout << tiempo << " ";
		for (int j = 0; j < drones.size(); j++)
		{
			if (drones[j].PilaA > drones[j].PilaB)
			{
				pilasA.push(drones[j].PilaA - drones[j].PilaB);
			}
			else if (drones[j].PilaB > drones[j].PilaA)
			{
				pilasB.push(drones[j].PilaB - drones[j].PilaA);
			}
			drones[j].PilaA = 0;
			drones[j].PilaB = 0;
		}

	}

	cout << endl;

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
