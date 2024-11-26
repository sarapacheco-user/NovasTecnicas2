#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
// vaiiiiii
    int n_cabos;
    cin >> n_cabos;
    
    // igual dos pokemons talvez va 
    priority_queue<int, vector<int>, greater<int>> cabos;

    
    for (int i = 0; i < n_cabos; i++) {
        int cabo;
        cin >> cabo;
        
        cabos.push(cabo);  
    }

    int custo_total = 0;

    
    while (cabos.size() > 1) {
        
        int cabo1 = cabos.top();
        cabos.pop();
        
        int cabo2 = cabos.top();
        cabos.pop();
        
        int custo = max(cabo1, cabo2);

        custo_total += custo;
        
        
        cabos.push(cabo1 + cabo2);
    }

    
    cout << custo_total << endl;

    return 0;
}
