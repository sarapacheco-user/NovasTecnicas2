// //B. LSB
// time limit per test1 second
// memory limit per test256 megabytes
// Em computação, um conceito que é bastante utilizado é um chamado de Least Significant Bit ou LSB, representado por LSB(N)
// , e significa o bit menos significativo de um número inteiro N
// .

// O bit menos significativo de um número é o bit mais à direita de sua representação binária que possui o valor 1. Por exemplo, no número 232
// , que possui a representação binária como 11101000, o seu LSB é o bit da posição de número 4, que é a posição mais a direita cujo o valor é 1
// .


// Nesta atividade sua tarefa é, dado um número, responder qual a posição do LSB desse número.

// Input
// A primeira linha da entrada contém um inteiro N
//  (1≤N≤100
// ), que representa o número de casos de testes. Cada uma das próximas N
//  linhas contém um inteiro V
//  (0≤V≤264−1
// ) que é o número cujo LSB
//  deve ser verificado.

// Output
// A saída deverá conter N
//  linhas, cada uma contendo um inteiro que representa a posição do LSB do número dado, ou "None" caso o valor de entrada seja zero, conforme os exemplos.




#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
std::string intToBinary(unsigned long long int numInt) {
    std::bitset<64> bitset(numInt);
    std::string StringBinario = bitset.to_string();
    return StringBinario;
}
int main() {
    // pf vai
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++){
        unsigned long long int inteiro = 0;
        cin >> inteiro ;
        if(inteiro == 0){
            cout << "None" << endl;
        }else{
            string stringBinaria = intToBinary(inteiro);
            size_t pos = stringBinaria.find_last_of("1");
            pos = 64 - pos;
            cout << pos << endl;
        }
    }
    // vai pelo amor de Deus
    return 0;
}
