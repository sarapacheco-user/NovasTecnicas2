#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Grafo {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;  // Lista de adjacência com pares (vértice, peso)

public:
    Grafo(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Adiciona uma aresta com peso ao grafo
    void adicionarAresta(int u, int v, int peso) {
        adjList[u].push_back({v, peso});
        adjList[v].push_back({u, peso});  // Grafo não direcionado
    }

    // Algoritmo de Dijkstra para encontrar os caminhos mínimos de um vértice fonte
    void dijkstra(int fonte) {
        vector<int> dist(vertices, INT_MAX);  // Distâncias de todos os vértices
        dist[fonte] = 0;  // A distância da fonte a ela mesma é 0

        // Fila de prioridade (min-heap) que armazena pares (distância, vértice)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, fonte});  // Adiciona a fonte na fila com distância 0

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // Se a distância já encontrada for menor, ignora
            if (d > dist[u]) continue;

            // Processa todos os vizinhos de u
            for (auto& adj : adjList[u]) {
                int v = adj.first;
                int peso = adj.second;

                // Relaxamento da aresta (distância mínima)
                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    pq.push({dist[v], v});
                }
            }
        }

        // Exibe as distâncias mínimas
        cout << "Distâncias mínimas a partir do vértice " << fonte << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Vértice " << i << ": " << (dist[i] == INT_MAX ? "Inf" : to_string(dist[i])) << endl;
        }
    }
};

int main() {
    Grafo g(5);

    // Adiciona arestas com peso
    g.adicionarAresta(0, 1, 10);
    g.adicionarAresta(0, 2, 5);
    g.adicionarAresta(1, 2, 2);
    g.adicionarAresta(1, 3, 1);
    g.adicionarAresta(2, 3, 9);
    g.adicionarAresta(3, 4, 4);
    
    // Aplica o algoritmo de Dijkstra a partir do vértice 0
    g.dijkstra(0);

    return 0;
}
