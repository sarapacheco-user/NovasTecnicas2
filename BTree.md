# Árvore B (B-Tree)
A Árvore B é uma árvore balanceada e ordenada onde cada nó pode ter múltiplos filhos e armazenar múltiplos valores. É comumente usada em sistemas de gerenciamento de bancos de dados e sistemas de arquivos.

Características
Cada nó pode ter entre t e 2t-1 filhos, onde t é a ordem da árvore.
Todos os nós são mantidos em uma ordem específica, permitindo buscas rápidas.
Operações Comuns
Busca: Encontrar um valor em um nó ou subárvore.
Inserção e Remoção: Inserir ou remover valores mantendo a estrutura balanceada.
Exemplo de código:
```cpp

struct BTreeNode {
    int* keys;
    int t;
    BTreeNode** children;
    int numKeys;
    bool leaf;

    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf), numKeys(0) {
        keys = new int[2 * t - 1];
        children = new BTreeNode *[2 * t];
    }
};

void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;
    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    }
}
```
Considerações Finais
Árvore Binária: A estrutura de dados mais simples e básica.
Árvore Binária de Busca (BST): Permite buscas eficientes, mas pode se tornar ineficiente se não for balanceada.
Árvore AVL: Garante operações balanceadas, mantendo a complexidade O(log n).
Árvore Red-Black: Uma alternativa balanceada com regras simples de balanceamento e desempenho eficiente.
Árvore B: Usada em bancos de dados e sistemas de arquivos, eficiente em grandes volumes de dados.
Cada tipo de árvore possui suas vantagens e desvantagens, dependendo do problema a ser resolvido. A escolha do tipo de árvore depende de como os dados serão acessados, modificados e armazenados.
