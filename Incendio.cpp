#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

// vaiiii
int menor_caminho(int inicio, int destino, vector<vector<int>>& grafo,  int n) {
    
    vector<int> dist(n + 1, numeric_limits<int>::max());
    
    queue<int> fila;
    
    
    fila.push(inicio);
    
    dist[inicio] = 0;

    while (!fila.empty()) {
        
        int atual = fila.front();
        fila.pop();

        for (int vizinho : grafo[atual]) {
            
            if (dist[vizinho] ==  numeric_limits<int>::max()) {
                
                dist[vizinho] = dist[atual] + 1;
                fila.push(vizinho);
                
            }
            
        }
        
    }

    return dist[destino];
}

int main() {
    int pontos;
    int corredores;
    cin >> pontos >> corredores;

    vector<vector<int>> grafo(pontos + 1);

    for (int i = 0; i < corredores; i++) {
        int a;
        int b;
        
        cin >> a >> b;
        
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int agente;
    int extintor;
    int foco;
    
    cin >> agente >> extintor >> foco;

    
    int caminho_agente_para_extintor = menor_caminho(agente, extintor, grafo, pontos);

    
    int caminho_extintor_para_foco = menor_caminho(extintor, foco, grafo, pontos);

    
    int resultado = caminho_agente_para_extintor + caminho_extintor_para_foco;

    cout << resultado << endl;

    return 0;
}
