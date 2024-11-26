#include <bits/stdc++.h>

using namespace std;

int main(void) {
    //SOCORRO VAI EU NAO AGUENTO MAIS
    int numNos;
    int consultas;
    
    cin >> numNos >> consultas;
    
    int tamArvore = numNos + 1;
    
    vector<int> arvore(tamArvore);
    
    arvore[0] = 0;

    for (int i = 1; i <= numNos; i++) {
        cin >> arvore[i];
    }

    for (int i = 0; i < consultas; i++) {
        int indiceConsulta;
        
        cin >> indiceConsulta;
        int pai = floor(arvore[indiceConsulta / 2]);

        if (pai == -1) {
            cout << "NULL" << endl;
            
        } else if (indiceConsulta == 1) {
            
            pai = arvore[1];
            if (pai == -1) {
                
                cout << "NULL" << endl;
            } else {
                
                cout << "RAIZ" << endl;
            }
        } else {
            
            cout << pai << endl;
        }
    }

    return 0;
}
