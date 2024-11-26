#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int main() {
    int n_enderecos_base;
    int n_entradas;
    
    cin >> n_enderecos_base >>  n_entradas;
    
    vector<list<int>>tabelaHash(n_enderecos_base);
    
    for (int i = 0; i < n_entradas; i++){
        int entrada;
        cin >> entrada;
        
        int indice = entrada % n_enderecos_base;
        tabelaHash[indice].push_back(entrada);
    }
// vaiii
    for (int j = 0; j < n_enderecos_base ; j++){
        
        cout << j << " -> ";
        
        for(auto entrada : tabelaHash[j]){
            cout << entrada << " -> ";
        }
        cout << "\\" << endl;
    }
    return 0;
}
