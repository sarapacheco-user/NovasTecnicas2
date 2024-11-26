#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(int no, vector<vector<int>>& grupos, vector<bool>& visitado) {
    visitado[no] = true;
    
    for (int vizinho : grupos[no]) {
        if (!visitado[vizinho]) {
            
            dfs(vizinho, grupos, visitado);
        }
    }
}

int main() {
    // vaiii
    int n_participantes;
    int n_pares;
    
    cin >> n_participantes >> n_pares;
    
    
    vector<vector<int>> grupos(n_participantes + 1);
    
  
    for (int i = 0; i < n_pares; i++) {
        int pessoa1;
        int pessoa2;
        
        cin >> pessoa1 >> pessoa2;
        grupos[pessoa1].push_back(pessoa2);
        grupos[pessoa2].push_back(pessoa1);
    }
    
    vector<bool> visitados(n_participantes + 1, false); 
    int gangues = 0;
    

    for (int i = 1; i <= n_participantes; i++) {
        
        if (!visitados[i]) {
            dfs(i, grupos, visitados);
            gangues++; 
        }
    }
    
    
    cout << gangues << " gangue(s) no clube da briga" << endl;
    
    return 0;
}
