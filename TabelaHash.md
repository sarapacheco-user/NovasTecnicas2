# Tabela Hash
Uma tabela hash é uma estrutura de dados que permite armazenar e acessar dados de maneira eficiente, utilizando uma função hash para mapear chaves para índices de um vetor. A principal vantagem das tabelas hash é a capacidade de realizar buscas, inserções e deleções de elementos com complexidade O(1), na média.

A tabela hash é composta por:

* Função Hash: Uma função que transforma uma chave em um índice dentro de um vetor ou array.
* Bucket (balde): Cada posição no vetor onde os elementos são armazenados. Em caso de colisão, vários elementos podem ser armazenados no mesmo bucket, utilizando uma técnica de resolução de colisões, como encadeamento (listas encadeadas) ou endereçamento aberto.

## Função Hash

```
int hashFunction(int key) {
    return key % tableSize;
}
```

## Adicionar Elemento

```
void insert(int key, int value) {
    int index = hashFunction(key);
    table[index].push_back({key, value});
}

```
## Buscar Elemento Search
```
int search(int key) {
    int index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return -1;  // Retorna -1 se o elemento não for encontrado
}
```

## Deletar Elemento

```
void remove(int key) {
    int index = hashFunction(key);
    auto& bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            return;
        }
    }
}
```

## Percorrer Tabela Hash

```
void traverse() {
    for (int i = 0; i < tableSize; ++i) {
        for (auto& pair : table[i]) {
            cout << "Chave: " << pair.first << " Valor: " << pair.second << endl;
        }
    }
}

```

