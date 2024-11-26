#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int main() {
    int n_elementos;
    long long soma_ideal;
    
    cin >> n_elementos >> soma_ideal;

    unordered_set<long long> elementos_vistos;

    for (int i = 0; i < n_elementos; ++i) {
        long long elemento;
        cin >> elemento;
        
        long long complemento = soma_ideal - elemento;

        if (elementos_vistos.find(complemento) != elementos_vistos.end()) {
            std::cout << elemento << " " << complemento << std::endl;
            return 0;
        }

        elementos_vistos.insert(elemento);
    }
// boraaaa
    cout << "Nao existe" << std::endl;
    return 0;
}

