#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>


using namespace std;

void bfs(int inicio, vector<vector<int>>& grafo, vector<bool>& visitado) {
    
    queue<int> fila;
    
    fila.push(inicio);
    
    visitado[inicio] = true;

    while (!fila.empty()) {
        
        int atual = fila.front();
        fila.pop();

        for (int amigo : grafo[atual]) {
            
            if (!visitado[amigo]) {
                
                visitado[amigo] = true;
                fila.push(amigo);
                
            }
            
        }
        
    }
    
}

int main() {
    
    int alunos;
    int amizades;
    
    cin >> alunos >> amizades;

    vector<vector<int>>  grafo(alunos + 1);

    for (int i = 0; i < amizades;  i++) {
        
        int a;
        int b;
        
        cin >> a >> b;
        
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    vector<bool>  visitado(alunos + 1,  false);
    
    int grupos = 0;
// vaiiiiiii
    for (int i = 1; i <= alunos; i++) {
        
        if (!visitado[i]) {
            
            grupos++;
            
            bfs(i, grafo, visitado);
        }
        
    }

    if (grupos == 1) {
        
        cout << "Todo mundo eh amigo de todo mundo" << endl;
        
    } else {
        cout << "Varios grupos de amigos" << endl;
    }

    return 0;
}
