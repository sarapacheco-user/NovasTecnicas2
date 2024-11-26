#include <iostream>
#include <vector>

using namespace std;


struct No {
	int valor;
	No* esquerda;
	No* direita;

	No(int val) : valor(val), esquerda(nullptr), direita(nullptr) {}
};


No* inserir(No* raiz, int valor) {
	if (raiz == nullptr) {
		return new No(valor);
	}
	if (valor < raiz->valor) {
		raiz->esquerda = inserir(raiz->esquerda, valor);
	} else {
		raiz->direita = inserir(raiz->direita, valor);
	}
	return raiz;
}

void percorrerInfixa(No* raiz, vector<int>& resultado) {
	if (raiz != nullptr) {
		percorrerInfixa(raiz->esquerda, resultado);
		resultado.push_back(raiz->valor);
		percorrerInfixa(raiz->direita, resultado);
	}
}

void percorrerPrefixa(No* raiz, vector<int>& resultado) {
	if (raiz != nullptr) {
		resultado.push_back(raiz->valor);
		percorrerPrefixa(raiz->esquerda, resultado);
		percorrerPrefixa(raiz->direita, resultado);
	}
}
// socorrooooooo
void percorrerPosfixa(No* raiz, vector<int>& resultado) {
	if (raiz != nullptr) {
		percorrerPosfixa(raiz->esquerda, resultado);
		percorrerPosfixa(raiz->direita, resultado);
		resultado.push_back(raiz->valor);
	}
}

int main() {
	int quantidadeNodos;
	cin >> quantidadeNodos;

	No* raiz = nullptr;
	for (int i = 0; i < quantidadeNodos; i++) {
		int valor;
		cin >> valor;
		raiz = inserir(raiz, valor);
	}

	vector<int> resultadoInfixa, resultadoPrefixa, resultadoPosfixa;

	percorrerInfixa(raiz, resultadoInfixa);
	percorrerPrefixa(raiz, resultadoPrefixa);
	percorrerPosfixa(raiz, resultadoPosfixa);


	cout << "In.:";
	for (int val : resultadoInfixa) {
		cout << " " << val;
	}
	cout << endl;

	cout << "Pre:";
	for (int val : resultadoPrefixa) {
		cout << " " << val;
	}
	cout << endl;

	cout << "Pos:";
	for (int val : resultadoPosfixa) {
		cout << " " << val;
	}
	cout << endl;

	return 0;
}
