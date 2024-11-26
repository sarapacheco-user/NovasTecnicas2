#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;


double f(double x, double A, double B, double C) {
    return A * x + B * cos(x) - C;
}

int main() {
  
    double A, B, C;
    cin >> A >> B >> C;

    
    double esquerda = 0.0, direita = 1e9;

    
    const double EPS = 1e-7;

    
    while (direita - esquerda > EPS) {
        double meio = (esquerda + direita) / 2;
        if (f(meio, A, B, C) > 0) {
            direita = meio;
        } else {
            esquerda = meio;
        }
    }

    double resultado = (esquerda + direita) / 2;
    cout << fixed << setprecision(4) << resultado << endl;

    return 0;
}
