#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Grafo {
private:
    vector<vector<int>> adjMatrix;
    int vertices;
    
public:
    Grafo(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));  // Inicializa a matriz com 0
    }

    void adicionarAresta(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;  // Grafo não direcionado
    }

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Grafo g(5);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(1, 4);

    cout << "DFS a partir do vértice 0: ";
    vector<bool> visited(5, false);
    g.dfs(0, visited);
    cout << endl;

    cout << "BFS a partir do vértice 0: ";
    g.bfs(0);
    cout << endl;

    return 0;
}
