# Árvore Red-Black
A Árvore Red-Black é uma árvore binária de busca balanceada, mas ao invés de manter a altura balanceada, ela utiliza cores (vermelho e preto) para garantir balanceamento aproximado e eficiência nas operações.

Características
Cada nó é colorido de vermelho ou preto.
A raiz é sempre preta, e as folhas (nós nulos) são pretas.
Dois nós vermelhos não podem ser adjacentes.
O caminho da raiz até qualquer folha ou nó nulo deve ter o mesmo número de nós pretos.
Operações Comuns
Inserção: Inserir um nó e garantir que as propriedades de balanceamento sejam mantidas.
Remoção: Manter as propriedades após a remoção de um nó.
Exemplo de código:
A implementação de uma árvore Red-Black é mais complexa e envolve várias operações de reestruturação e coloração.

```cpp
Copiar código
struct RBNode {
    int value;
    RBNode *parent, *left, *right;
    bool color;  // false para preto, true para vermelho

    RBNode(int val) : value(val), parent(nullptr), left(nullptr), right(nullptr), color(true) {}
};
```
