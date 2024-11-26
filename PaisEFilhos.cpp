#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int numNos;
    int consultas;
    
    cin >> numNos >> consultas;
    
    vector<int> arvore(numNos + 1);
    for (int i = 1; i <= numNos; i++) {
        
        cin >> arvore[i];
    }
    
    for (int i = 0; i < consultas; i++) {
        int consulta;
        cin >> consulta;

        if (arvore[1] == -1) {  
            cout << "NULL" << endl;
            continue;
        }

        int paiIndex = consulta / 2;  
        
        int noEsquerdoIndex =  consulta * 2; 
        int noDireitoIndex = consulta * 2 + 1;  

     
        if (consulta == 1) {
            cout << "RAIZ - ";
        } else {
            // agr tem que irrr
            cout << (arvore[paiIndex] == -1 ? "NULL" : to_string(arvore[paiIndex])) << " - ";
        }

        
        string filhoEsquerdo = (noEsquerdoIndex <= numNos && arvore[noEsquerdoIndex] != -1) ? to_string(arvore[noEsquerdoIndex]) : "NULL";
        
        string filhoDireito = (noDireitoIndex <= numNos && arvore[noDireitoIndex]  != -1) ?  to_string(arvore[noDireitoIndex]) : "NULL";

        cout << filhoEsquerdo << " " << filhoDireito << endl;
    }
    
    return 0;
}
