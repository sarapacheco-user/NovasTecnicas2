#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int blocos;
    cin >> blocos;

    for (int i = 0; i < blocos; i++) {
        string stringCatalogo;
        string stringOriginal;
        // vaiiiiiiiiiiiiiiii
        cin >> stringCatalogo >> stringOriginal;

        
        unordered_set<char> catalogoSet(stringCatalogo.begin(), stringCatalogo.end());

        
        int contagemPedras = 0;
        for (char c : stringOriginal) {
            if (catalogoSet.count(c) > 0) {
                contagemPedras++;
            }
        }

        cout << "Contem " << contagemPedras << " pedras negociaveis" << endl;
    }

    return 0;
}
