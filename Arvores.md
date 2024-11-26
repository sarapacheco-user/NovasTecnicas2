# Resumo sobre Árvores em C++

As **árvores** são estruturas de dados hierárquicas compostas por nós, onde cada nó tem um valor e referências (ou ponteiros) para seus filhos. Cada árvore tem uma raiz, que é o ponto de entrada para acessar os elementos. As árvores são amplamente usadas em diversas áreas de ciência da computação, como em sistemas de arquivos, bancos de dados, algoritmos de busca e muito mais.

## Tipos Comuns de Árvores

### 1. Árvore Binária
Uma **árvore binária** é uma árvore em que cada nó tem no máximo dois filhos, chamados de **filho esquerdo** e **filho direito**.

#### Características
- Cada nó possui um valor.
- Um nó pode ter, no máximo, dois filhos.
- É usada em muitas implementações de algoritmos de busca.

#### Operações Comuns
- **Inserção**: Insere um novo nó de acordo com a regra da árvore binária (geralmente comparando com o nó pai).
- **Remoção**: Remove um nó e reorganiza a árvore para manter sua estrutura válida.
- **Percorrimento**: Existem três maneiras principais de percorrer uma árvore binária:
  - **Pré-ordem**: Visita o nó antes de seus filhos.
  - **Em-ordem**: Visita o nó entre os filhos esquerdo e direito.
  - **Pós-ordem**: Visita o nó após os filhos esquerdo e direito.

#### Exemplo de código:

```cpp
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
    } else if (value < root->value) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}
