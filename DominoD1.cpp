#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int quantidade_pecas;
    int lado_esquerdo;
    int lado_direito;
    
    queue<int> fila_lado_esquerdo;
    queue<int> fila_lado_direito;

    cin >> quantidade_pecas;
    while (quantidade_pecas--) {
        
        cin >> lado_esquerdo >> lado_direito;
        fila_lado_esquerdo.push(lado_esquerdo);
        fila_lado_direito.push(lado_direito);
    }

    bool jogo_em_andamento = true;
    while (jogo_em_andamento) {
        
        if (fila_lado_esquerdo.empty() && fila_lado_direito.empty()) {
            jogo_em_andamento = false;
            break;
        }

        cout << fila_lado_esquerdo.front() << " " << fila_lado_direito.front() << endl;
        fila_lado_esquerdo.pop();
        fila_lado_direito.pop();

        if (fila_lado_esquerdo.empty() && fila_lado_direito.empty()) {
            jogo_em_andamento = false;
            break;
        }

        if ((fila_lado_esquerdo.front() + fila_lado_direito.front()) == 7) {
            fila_lado_esquerdo.push(fila_lado_esquerdo.front());
            fila_lado_direito.push(fila_lado_direito.front());
        }

        fila_lado_esquerdo.pop();
        fila_lado_direito.pop();
    }

    return 0;
}
