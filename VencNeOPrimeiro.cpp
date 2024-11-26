#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numClientes, rankPosicao;
    cin >> numClientes >> rankPosicao;
// BORAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    set<int> cadeirasEscolhidas;

    for (int i = 0; i < numClientes; i++) {
        int cadeiraAtual;
        cin >> cadeiraAtual;
        
        
        cadeirasEscolhidas.insert(cadeiraAtual);
        
         auto it = cadeirasEscolhidas.begin();
        advance(it, min(rankPosicao - 1, static_cast<int>(cadeirasEscolhidas.size()) - 1));
        
        cout << *it << endl;
    }

    return 0;
}
