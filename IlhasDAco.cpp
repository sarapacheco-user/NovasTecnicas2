#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

int bfs(int inicio, int destino,  vector<vector<int>>& grafo,  int num_ilhas) {
    
    vector<int> dist(num_ilhas + 1,  numeric_limits<int>::max());
    
    queue<int> fila;
    fila.push(inicio);
    
    dist[inicio] = 0;
    
// vaiii
    while (!fila.empty()) {
        
        int atual = fila.front();
        fila.pop();

        for (int vizinho : grafo[atual]) {
            
            if (dist[vizinho] == numeric_limits<int>::max()) {
                dist[vizinho] = dist[atual] + 1;
                
                fila.push(vizinho);
            }
        }
    }

    return (dist[destino] == numeric_limits<int>::max()) ? -1 : dist[destino];
}

int main() {
    
    int ilhas;
    int pontes;
    
    cin >> ilhas >> pontes;

    vector<vector<int>> grafo(ilhas + 1);

    for (int i = 0; i < pontes; i++) {
        int x;
        int y;
        cin >> x >> y;
        
        grafo[x].push_back(y);
        grafo[y].push_back(x);
        
    }

    int resultado = bfs(1, ilhas, grafo, ilhas);
    cout << resultado << endl;

    return 0;
}
