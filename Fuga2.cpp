#include <bits/stdc++.h>
using namespace std;

void calcular_distancias(int origem, vector<int>& distancias, const vector<vector<int>>& grafo, const int infinito) {
    queue<int> fila;
    fila.push(origem);
    distancias[origem] = 0;
    while (!fila.empty()) {
        int no_atual = fila.front();
        fila.pop();
        for (auto vizinho : grafo[no_atual]) {
            if (distancias[vizinho] == infinito) {
                fila.push(vizinho);
                distancias[vizinho] = distancias[no_atual] + 1;
            }
        }
    }
}

int main() {
    int num_celas, num_corredores, num_cameras;
    cin >> num_celas >> num_corredores >> num_cameras;

    vector<vector<int>> grafo_prisao(num_celas + 1);
    vector<int> celas_com_cameras;

    int cela_camera;
    while (num_cameras--) {
        cin >> cela_camera;
        celas_com_cameras.push_back(cela_camera);
    }

    int cela1, cela2;
    auto grafo_prisao_sem_cameras = grafo_prisao;
    while (num_corredores--) {
        cin >> cela1 >> cela2;

        if (find(celas_com_cameras.begin(), celas_com_cameras.end(), cela1) != celas_com_cameras.end() || 
            find(celas_com_cameras.begin(), celas_com_cameras.end(), cela2) != celas_com_cameras.end()) {
            grafo_prisao[cela1].push_back(cela2);
            grafo_prisao[cela2].push_back(cela1);  
            continue;
        }

        grafo_prisao[cela1].push_back(cela2);
        grafo_prisao[cela2].push_back(cela1);
        grafo_prisao_sem_cameras[cela1].push_back(cela2);
        grafo_prisao_sem_cameras[cela2].push_back(cela1);
    }

    const int infinito = 0x3f3f3f3f;
    vector<int> distancias_chave(num_celas + 1, infinito);
    vector<int> distancias_saida(num_celas + 1, infinito);

    int cela_inicio, cela_saida, cela_chave, tempo_chave, tempo_saida;
    cin >> cela_inicio >> cela_saida >> cela_chave;

    calcular_distancias(cela_inicio, distancias_chave, grafo_prisao_sem_cameras, infinito);
    tempo_chave = distancias_chave[cela_chave];

    if (tempo_chave == infinito) {
        cout << "impossivel fugir";
        return 0;
    }

    tempo_chave = tempo_chave * 2;

    calcular_distancias(cela_inicio, distancias_saida, grafo_prisao, infinito);
    tempo_saida = distancias_saida[cela_saida];

    cout << tempo_chave << " " << tempo_saida;

    return 0;
}
