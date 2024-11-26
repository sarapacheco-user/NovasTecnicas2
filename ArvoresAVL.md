# Árvore AVL (Árvore de Pesquisa Balanceada)
Uma Árvore AVL é uma árvore binária de busca balanceada. Ela mantém um equilíbrio entre os subárvores esquerda e direita de cada nó, garantindo que a diferença de altura entre os dois filhos de um nó seja no máximo 1.

Características
Balanceamento: Garante que a árvore permaneça balanceada após cada inserção e remoção.
Altura: A altura da árvore é mantida como O(log n), garantindo que as operações sejam eficientes.
Operações Comuns
Rotação: A operação de rotação é usada para balancear a árvore. Existem quatro tipos principais de rotação:
Rotação à direita
Rotação à esquerda
Rotação à direita-esquerda
Rotação à esquerda-direita
Exemplo de código:
```cpp
Copiar código
struct AVLNode {
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int balanceFactor(AVLNode* node) {
    return height(node->left) - height(node->right);
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
```
