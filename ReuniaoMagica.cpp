#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numeroDeTestes;
    cin >> numeroDeTestes;

    while (numeroDeTestes--) {
        string baralho1, baralho2;
        cin >> baralho1 >> baralho2;

        set<char> cartasBaralho1(baralho1.begin(), baralho1.end());
        set<char> cartasBaralho2(baralho2.begin(), baralho2.end());
        set<char> cartasComuns;

        for (char carta : cartasBaralho1) {
            if (cartasBaralho2.count(carta)) {
                cartasComuns.insert(carta);
            }
        }

        if (cartasComuns.empty()) {
            cout << "Baralhos prontos para o duelo\n";
        } else {
            for (char carta : cartasComuns) {
                cout << carta;
            }
            // boraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
            cout << '\n';
        }
    }

    return 0;
}
