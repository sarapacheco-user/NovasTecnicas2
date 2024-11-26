#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grafo {
private:
    vector<vector<int>> adjList;  // Lista de adjacência
    int vertices;

public:
    Grafo(int v) {
        vertices = v;
        adjList.resize(v);  // Inicializa o vetor com v listas
    }

    // Adiciona uma aresta entre os vértices i e j
    void adicionarAresta(int i, int j) {
        adjList[i].push_back(j);
        adjList[j].push_back(i);  // Grafo não direcionado
    }

    // Busca em profundidade (DFS)
    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";  // Processa o vértice

        for (int adj : adjList[v]) {
            if (!visited[adj]) {
                dfs(adj, visited);  // Visita recursivamente
            }
        }
    }

    // Busca em largura (BFS)
    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";  // Processa o vértice

            for (int adj : adjList[v]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
    }
};

int main() {
    Grafo g(5);

    // Adiciona arestas ao grafo
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(1, 4);

    // Exibe DFS e BFS a partir do vértice 0
    cout << "DFS a partir do vértice 0: ";
    vector<bool> visited(5, false);
    g.dfs(0, visited);
    cout << endl;

    cout << "BFS a partir do vértice 0: ";
    g.bfs(0);
    cout << endl;

    return 0;
}
