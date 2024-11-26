#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
// socorrrooooooooo
	int qtd_pokemons;
	cin >> qtd_pokemons;


	priority_queue<pair<int, string>> pokemons;

	for (int i = 0; i < qtd_pokemons; i++) {
		string nome;
		int poder;
		cin >> nome >> poder;
		pokemons.push({poder, nome});
	}


	if (pokemons.size() == 1) {
		auto vencedor = pokemons.top();
		cout << vencedor.second << " venceu com " << vencedor.first << endl;
		return 0;
	}


	while (pokemons.size() > 1) {
		auto primeiro = pokemons.top();
		pokemons.pop();
		
		auto segundo = pokemons.top();
		pokemons.pop();

		int poder1 = primeiro.first;
		string nome1 = primeiro.second;
		
		int poder2 = segundo.first;
		string nome2 = segundo.second;


		if (poder1 == poder2) {
			cout << nome1 << " (" << poder1 << ") x (" << poder2 << ") " << nome2 << " : empate" << endl;
		} else if (poder1 > poder2) {
			cout << nome1 << " (" << poder1 << ") x (" << poder2 << ") " << nome2 << " : " << nome1 << " venceu" <<  endl;
			int novo_poder = poder1 - poder2;
			
			pokemons.push({novo_poder, nome1});
		} else {
			cout << nome2 << " (" << poder2 << ") x (" << poder1 << ") " << nome1 << " : " << nome2 << " venceu" << endl;
			int novo_poder = poder2 - poder1;
			pokemons.push({novo_poder, nome2});
		}
	}


	if (!pokemons.empty()) {
		auto vencedor = pokemons.top();
		
		cout << vencedor.second << " venceu com " << vencedor.first << endl;
	} else {
		cout << "nenhum vencedor" << endl;
	}

	return 0;
}
