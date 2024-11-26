#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int vertices;
    int conexoes;
    // vaii
    cin >> vertices >> conexoes;

    vector<vector<int>> grafo(vertices, vector<int>( vertices , 0));

    for (int i = 0; i < conexoes; i++) {
        
        int origem, destino;
        cin >> origem >> destino;
        
        origem--;
        destino--;
        
        grafo[origem][destino] = 1;
        grafo[destino][origem] = 1;
    }

    for (int i = 0; i < vertices; i++) {
        
        for (int j = 0; j < vertices; j++) {
            
            cout << grafo[i][j];
            
            if (j < vertices - 1) cout << " ";
            
        }
        cout << endl;
    }

    return 0;
}
