#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numeroAlunos;
    cin >> numeroAlunos;

    set<string> itensChurrasco;
    vector<string> mensagens;

    for (int i = 0; i < numeroAlunos; ++i) {
        int quantidadeItens;
        cin >> quantidadeItens;

        for (int j = 0; j < quantidadeItens; ++j) {
            string item;
            cin >> item;

            if (itensChurrasco.find(item) == itensChurrasco.end()) {
                itensChurrasco.insert(item);
                mensagens.push_back("adicionando " + item);
            } else {
                mensagens.push_back(item + " ja tem");
            }
        }
    }

// agr tem que irrrrrrr
    for (const auto& mensagem : mensagens) {
        cout << mensagem << endl;
    }

    vector<string> itensOrdenados(itensChurrasco.begin(), itensChurrasco.end());
    sort(itensOrdenados.begin(), itensOrdenados.end());

    cout << "Itens do churrasco:" << endl;
    for (const auto& item : itensOrdenados) {
        cout << item << endl;
    }

    return 0;
}
