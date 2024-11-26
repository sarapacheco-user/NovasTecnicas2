#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n_elementos;
    long long soma_ideal;
    cin >> n_elementos >> soma_ideal;
 
    vector<long long> elementos(n_elementos);
    for (int i = 0; i < n_elementos; ++i) {
        cin >> elementos[i];
    }
 
    sort(elementos.begin(), elementos.end());
 
    for (int j = 0; j < n_elementos - 2; ++j) {
        long long complemento = soma_ideal - elementos[j];
        
        int esq = j + 1;
        int dir = n_elementos - 1;
 
        while (esq < dir) {
            long long soma_dois = elementos[esq] + elementos[dir];
 
            if (soma_dois == complemento) {
                
                cout << elementos[j] << " " << elementos[esq] << " " << elementos[dir] << endl;
                return 0;
            }
            else if (soma_dois < complemento) {
                ++esq;
            } else {
                --dir;
            }
        }
    }
// boraaaa
    cout << "Nao existe" << std::endl;
    return 0;
}
