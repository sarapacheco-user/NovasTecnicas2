#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vaiiiii
    unordered_map<string, int> criminosos;
    string nome;
    int ofensa;
    
    while (cin >> nome >> ofensa && nome != "fim" && ofensa != 0) {
        criminosos[nome]++;
        
        if (criminosos[nome] == 1) {
            
            cout << nome << " eh reu primario" << '\n';        
        } else {
            cout << nome << " eh reincidente com " << criminosos[nome] - 1 << " crime(s)" << '\n';
        }
    }

    return 0;
}
