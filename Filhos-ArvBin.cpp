#include <iostream>
#include <vector>

using namespace std;

class ArvoreBinaria {
private:
	vector<int> nos;

public:
	void inserir(int valor) {
		nos.push_back(valor);
	}

	bool estaVazia() {
		return nos.empty();
	}

	int valorNoIndice(int indice) {
		if (indice >= 0 && indice < nos.size()) {
			return nos[indice];
		}
		return -1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ArvoreBinaria arvore;

	int n_de_nos, consultas;
	cin >> n_de_nos >> consultas;

	for (int i = 0; i < n_de_nos; i++) {
		int no;
		cin >> no;
		arvore.inserir(no);
	}


	if (arvore.estaVazia()) {
		cout << "NULL" << endl;
		return 0;
	}

	for (int i = 0; i < consultas; i++) {
		int indice;
		cin >> indice;

// vai pelo amor de Deussss
		int indiceFilhoEsq = 2 * indice - 1;
		int indiceFilhoDir = 2 * indice;

		int filho1 = arvore.valorNoIndice(indiceFilhoEsq);
		int filho2 = arvore.valorNoIndice(indiceFilhoDir);


		if (arvore.valorNoIndice(indice - 1) == -1) {
			cout << "NULL" << endl;

		} else if (filho1 == -1 && filho2 == -1) {
			cout << "NULL NULL" << endl;
		} else {
			cout << (filho1 == -1 ? "NULL" : to_string(filho1)) << " ";
			cout << (filho2 == -1 ? "NULL" : to_string(filho2)) << endl;
		}
	}

	return 0;
}
