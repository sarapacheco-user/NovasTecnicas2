/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <bits/stdc++.h>

struct Aresta{
    int peso;
    int destino;
    Aresta(int d, int p) : destino(d), peso(p) {}
};

int dijkstra(int n, vector<vector<Aresta>>& grafo, int inicio, int fim){
    vector<int>dist(n+1,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[inicio] = 0;
    
    pq.push({0,inicio});
    
    while(!pq.empty()){
        int no = pq.top().second;
        int distancia = pq.top().first;
        
        pq.pop();
        
        if (distancia > dist[no]) continue;
        
        for (const Aresta& e  : grafo[no]){
            int proximo_no = e.destino;
            int peso_no = e.peso;
            
            if(dist[no] + peso_no < dist[proximo_no] ){
                dist[proximo_no] = dist[no] + peso_no;
                pq.push({dist[proximo_no],proximo_no});
            }
        }
    }
    return dist[fim] == INT_MAX ? -1 : dist[fim];
}







int bfs(int inicio, int fim , vector<vector<int>>& grafo, int n) {
    vector<int> dist(n+1, numeric_limits<int>::max());
    queue<int> fila;
    
    fila.push(inicio);
    
    dist[inicio] = 0;

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
return dist[fim];
}

int main(){
    int vertices;
    int arestas;
    cin >> vertices>> arestas;
    vector<vector<Aresta>> grafo(vertices + 1 );
    
    for (int i = 0; i < arestas ; i ++){
        int inicio;
        int fim;
        int peso_aresta;
        cin >> inicio >> fim >> peso_aresta;
        
        grafo[inicio].push_back(Aresta(fim,peso_aresta));
        grafo[fim].push_back(Aresta(inicio,peso_aresta));
        
    }
    
    int resultado = dijkstra(vertices,grafo,1,vertices);
    
    if(resultado == -1 ){
        cout<< "Preso no IDP" << endl;
    }else{
        cout<< "Distancia para chegar em casa: "<< resultado  << endl;
    }
    
        
    return 0;
}
