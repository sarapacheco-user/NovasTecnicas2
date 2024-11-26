#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    
    int numeroDeArquivos;
    cin >> numeroDeArquivos;

    while (numeroDeArquivos--) {
        int numeroDeLinhas;
        
        cin >> numeroDeLinhas;
        unordered_set<string> registros;
        
        int contagemErros = 0;

        for (int i = 0; i < numeroDeLinhas; ++i) {
            string registroEstudante;
            int matriculaEstudante;
            string nomeDisciplina;

            cin >> matriculaEstudante >> nomeDisciplina;

            registroEstudante = to_string(matriculaEstudante) + " " + nomeDisciplina;

            if (registros.find(registroEstudante) != registros.end()) {
                ++contagemErros;
            } else {
                registros.insert(registroEstudante);
            }
        }

        if (contagemErros == 0) {
            cout << "Arquivo OK" << endl;
            // aq vai
        } else {
            cout << "Corrompido com " << contagemErros << " erro(s)" << endl;
        }
    }

    return 0;
}
