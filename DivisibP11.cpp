#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // pf vai
    int n;
 
    while (cin >> n && n != -1) {
        char num[100001];
        cin >> num;
        int somaPar = 0;
        int somaImpar = 0;
        int difSomas = 0;
      for (int i = 0; i < n; i++) {
          if(i==0 || i % 2 == 0){
            somaPar += num[i] - '0';
        }else {
            somaImpar += num[i] - '0';
        }
      }
      difSomas = somaPar - somaImpar;
        if (difSomas % 11 == 0) {
            cout << num << ": "<< somaPar << " - " << somaImpar << " = " << difSomas << " - sim" << endl;
        } else {
            cout << num << ": "<< somaPar << " - " << somaImpar << " = " << difSomas << " - nao" << endl;
        }
    }
    return 0;
}
