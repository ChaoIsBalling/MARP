
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include<queue>
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
struct tareas
{
	int ini;
	int fin;
	int repeticion;
};
bool operator<(tareas a, tareas b)
{
	return a.ini > b.ini;
}
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, M, T;
	cin >> N >> M >> T;
	if (!std::cin)  // fin de la entrada
		return false;
	priority_queue<tareas> mult;

	int ini;
	int fin;
	int temp;
	for (int i = 0;i < N;i++)
	{
		cin >> ini >> fin;
		mult.push({ ini,fin,0 });
	}
	for (int i = 0;i < M;i++)
	{
		cin >> ini >> fin >> temp;
		mult.push({ ini,fin,temp });
	}
	bool conflict = false;
	// resolver el caso posiblemente llamando a otras funciones
	int ocupado = 0;
	while (!conflict&&!mult.empty()&&mult.top().ini<T)
	{
		if (mult.top().ini < ocupado)
		{
			conflict = true;
		}
		else
		{
			auto primera = mult.top();
			ocupado = primera.fin;
			mult.pop();
			if (primera.repeticion != 0)
			{
				primera.ini += primera.repeticion;
				primera.fin += primera.repeticion;
				mult.push(primera);
			}
		}
	}
	// escribir la solución

	if (conflict)
		cout << "SI\n";
	else
		cout << "NO\n";
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
