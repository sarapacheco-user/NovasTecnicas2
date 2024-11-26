#include <bits/stdc++.h>

using namespace std;

int main() {
    int totalParticipantes;
    
    int totalSorteios;
    cin >> totalParticipantes >> totalSorteios;
    
    cin.ignore(); 

    unordered_map<string, set<string>> brindesParticipantes;

    for (int i = 0; i < totalParticipantes; i++) {
        
        string linha;
        
        getline(cin, linha);
        
        
        istringstream iss(linha);
        
        // EU NN AGUENTO MAISSS
        string nomeParticipante;
        string brinde1;
        string brinde2;
        string brinde3;
        
        iss >> nomeParticipante >> brinde1 >> brinde2 >> brinde3;
        
        brindesParticipantes[nomeParticipante] = {brinde1, brinde2, brinde3};
    }

    for (int i = 0; i < totalSorteios; ++i) {
        string linha;
        
        getline(cin, linha);
        
        istringstream iss(linha);
        string nomeParticipanteFeedback;
        string brindeRecebido;
        
        iss >> nomeParticipanteFeedback >> brindeRecebido;

        if (brindesParticipantes.find(nomeParticipanteFeedback) != brindesParticipantes.end()) {
            if (brindesParticipantes[nomeParticipanteFeedback].find(brindeRecebido)  != brindesParticipantes[nomeParticipanteFeedback].end()) {
               
                cout << nomeParticipanteFeedback << " conseguiu ganhar " << brindeRecebido << "!" << endl;
            } else {
                
                cout << nomeParticipanteFeedback << " infelizmente ganhou " << brindeRecebido << "..." << endl;
            }
        } else {
            
        cout << nomeParticipanteFeedback << " queria ganhar qualquer coisa e ganhou " << brindeRecebido << "!" << endl;
        }
        
        
        
        
    }

    return 0;
}
