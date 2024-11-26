#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// bora radix sorttt
void countingSort(vector<unsigned long long int>& arr, int exp) {
    int n = arr.size();
    vector<unsigned long long int> output(n);
    
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<unsigned long long int>& arr) {
    
    unsigned long long int maxVal = *max_element(arr.begin(), arr.end());

    for (unsigned long long int exp = 1; maxVal / exp > 0; exp *= 10)
    
        countingSort(arr, exp);
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    unsigned long long int q_alunos;
    cin >> q_alunos;

    vector<unsigned long long int> notas(q_alunos);

    for (unsigned long long int i = 0; i < q_alunos; i++) {
        cin >> notas[i];
    }

    radixSort(notas);
    
    for (unsigned long long int nota : notas) {
        cout << nota << '\n';
    }

    return 0;
}
