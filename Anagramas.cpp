#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n_testes;
    cin >> n_testes;
    for (int i=0; i< n_testes; i++){
        bool ana = true;
        string pal1;
        string pal2;
        unordered_set<char> charsPal1;
        cin >> pal1 >> pal2;
        // vaiiiii
        if (pal1.size() != pal2.size()){
            cout << "DIFERENTES" << endl;
            ana = false;
        }else{
            unordered_map<char, int> freqPal1;
            unordered_map<char, int> freqPal2;

            
            for (char c : pal1) {
                freqPal1[c]++;
            }
            for (char c : pal2) {
                freqPal2[c]++;
            }

            
            if (freqPal1 != freqPal2) {
                cout << "DIFERENTES" << endl;
                ana = false;
            }
        }
        if (ana) {
            cout << "ANAGRAMAS" << endl;
        }
    }
    return 0;
}
