#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

struct Aresta {
    
    int destino;
    int peso;
    Aresta(int d, int p) : destino(d), peso(p) {}
    
};
// vaii 
int dijkstra(int n, vector<vector<Aresta>>& grafo, int inicio, int destino) {
    
    vector<int> dist(n + 1, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[inicio] = 0;
    
    pq.push({0, inicio});

    while (!pq.empty()) {
        
        int u = pq.top().second;
        int d = pq.top().first;
        
        pq.pop();

        if (d > dist[u]) continue;

        for (const Aresta& aresta : grafo[u]) {
            
            int v = aresta.destino;
            int peso = aresta.peso;

            if (dist[u] + peso < dist[v]) {
                
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
                
            }
            
        }
        
    }

    return dist[destino] ==  INT_MAX ? -1 :  dist[destino];
}

int main() {
    
    int n;
    int m;
    
    cin >> n >> m;

    vector<vector<Aresta>> grafo(n + 1);

  
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        int w;
        
        cin >> u >> v >> w;
        
        grafo[u].push_back(Aresta(v, w));
        grafo[v].push_back(Aresta(u, w));
    }

   
    int resultado = dijkstra(n, grafo, 1, n);

    if (resultado == -1) {
        
        cout << "Preso no IDP" << endl;
        
    } else {
        
        cout << "Distancia para chegar em casa: " << resultado << endl;
    }

    return 0;
}
