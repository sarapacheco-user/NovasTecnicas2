#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int bfs(int inicio, vector<vector<int>>& grafo, vector<bool>& visitado) {
    // vaiii
    queue<int> fila;
    fila.push(inicio);
    
    visitado[inicio] = true;
    int tamanho = 1;

    while (!fila.empty()) {
        
        int atual = fila.front();
        fila.pop();

        for (int amigo : grafo[atual]) {
            
            if (!visitado[amigo]) {
                
                visitado[amigo] = true;
                fila.push(amigo);
                tamanho++;
                
            }
        }
    }
    return tamanho;
}

int main() {
    
    int alunos;
    int duplas;
    
    cin >> alunos >> duplas;

    vector<vector<int>> grafo(alunos +  1);

    for (int i = 0; i < duplas; i++) {
        int a;
        int b;
        
        cin >> a >> b;
        
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    vector<bool> visitado(alunos + 1, false);
    int maior_grupo = 0;

    for (int i = 1; i <= alunos; i++) {
        
        if (!visitado[i]) {
            
            int tamanho_grupo = bfs(i, grafo,  visitado);
            maior_grupo = max(maior_grupo, tamanho_grupo);
        }
    }

    cout << "O grupo mais numeroso tem " <<  maior_grupo << " aluno(s)" << endl;

    return 0;
}
