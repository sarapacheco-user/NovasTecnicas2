# Resumo sobre Priority Queue (Fila de Prioridade) em C++

Uma **Priority Queue** (Fila de Prioridade) é uma estrutura de dados em que cada elemento tem uma **prioridade associada**. Os elementos com maior prioridade são retirados primeiro, independentemente da ordem de inserção. Fila de prioridade é frequentemente implementada usando uma **heap** (geralmente uma heap binária), onde a estrutura garante que o elemento de maior prioridade esteja sempre na raiz, permitindo acessos rápidos ao elemento de maior prioridade.

## Características Principais

- **Ordenação de Elementos**: A fila de prioridade permite que os elementos sejam acessados em ordem de prioridade, não necessariamente em ordem de inserção.
- **Heap**: A implementação mais comum da fila de prioridade é através de uma heap, que é uma árvore binária completa. Na heap, cada nó segue uma relação de prioridade com seus filhos.
  - **Max-Heap**: O valor de cada nó é maior ou igual ao de seus filhos, o que garante que o maior elemento esteja sempre na raiz.
  - **Min-Heap**: O valor de cada nó é menor ou igual ao de seus filhos, garantindo que o menor elemento esteja na raiz.

## Principais Operações em Priority Queue

### 1. Inserir Elemento (Push)
A operação de inserção insere um novo elemento na fila de prioridade, mantendo a estrutura da heap. Após a inserção, a heap é ajustada para garantir que a propriedade de heap seja mantida.

**Exemplo de código** (com `std::priority_queue`):

```cpp
#include <queue>

std::priority_queue<int> pq;  // Fila de prioridade que é uma Max-Heap

void insert(int element) {
    pq.push(element);
}
```

```cpp
int top() {
    return pq.top();  // Retorna o elemento de maior prioridade
}

```

```cpp
bool isEmpty() {
    return pq.empty();  // Retorna true se a fila estiver vazia
}


```
```cpp
int size() {
    return pq.size();  // Retorna o número de elementos na fila
}
```
```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Max-Heap (maior valor tem maior prioridade)
    priority_queue<int> pq;

    // Inserção de elementos
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    // Acessando o topo (maior prioridade)
    cout << "Elemento de maior prioridade: " << pq.top() << endl;

    // Removendo o elemento de maior prioridade
    pq.pop();

    // Acessando o novo topo
    cout << "Novo topo após remoção: " << pq.top() << endl;

    // Verificando o tamanho da fila
    cout << "Tamanho da fila: " << pq.size() << endl;

    // Verificando se a fila está vazia
    cout << "A fila está vazia? " << (pq.empty() ? "Sim" : "Não") << endl;

    return 0;
}

```

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Para que a fila seja uma min-heap, com menor valor tendo maior prioridade
    }
};

int main() {
    priority_queue<int, vector<int>, Compare> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Elemento de maior prioridade (menor valor): " << pq.top() << endl;

    return 0;
}

```
