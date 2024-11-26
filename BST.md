#  Árvore Binária de Busca (Binary Search Tree - BST)
A Árvore Binária de Busca (BST) é um tipo especial de árvore binária em que, para cada nó:

Todos os elementos à esquerda do nó têm valores menores.
Todos os elementos à direita do nó têm valores maiores.
Características
Suporta operações eficientes de busca, inserção e remoção.
Em uma árvore balanceada, a complexidade das operações é O(log n).
Operações Comuns
Busca: Encontrar um nó específico na árvore.
Inserção e Remoção: Manter a estrutura da árvore após cada operação.
Exemplo de código:
```cpp

struct BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, int value) {
    if (root == nullptr) return new BSTNode(value);
    if (value < root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

BSTNode* search(BSTNode* root, int value) {
    if (root == nullptr || root->value == value) return root;
    if (value < root->value) return search(root->left, value);
    return search(root->right, value);
}
```
