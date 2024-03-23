// AlgorirmoBellmanFord.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Estructura para representar una arista
struct Arista {
    int origen, destino, peso;
};

// Función para ejecutar el algoritmo de Bellman-Ford
void bellmanFord(vector<Arista>& aristas, int numVertices, int origen) {
    vector<int> distancias(numVertices, numeric_limits<int>::max());
    distancias[origen] = 0;

    // Relajar todas las aristas V-1 veces
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const auto& arista : aristas) {
            int u = arista.origen;
            int v = arista.destino;
            int peso = arista.peso;
            if (distancias[u] != numeric_limits<int>::max() && distancias[u] + peso < distancias[v]) {
                distancias[v] = distancias[u] + peso;
            }
        }
    }

    // Verificar ciclos de peso negativo
    for (const auto& arista : aristas) {
        int u = arista.origen;
        int v = arista.destino;
        int peso = arista.peso;
        if (distancias[u] != numeric_limits<int>::max() && distancias[u] + peso < distancias[v]) {
            cout << "El grafo contiene un ciclo de peso negativo\n";
            return;
        }
    }

    // Imprimir las distancias más cortas desde el origen
    cout << "Vertice \t Distancia desde el origen\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << "\t\t" << distancias[i] << "\n";
    }
}

int main() {
    int numVertices = 5;
    vector<Arista> aristas = { {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3} };
    int origen = 0;

    bellmanFord(aristas, numVertices, origen);

    return 0;
}
