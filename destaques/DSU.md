# Disjoint Set Union (DSU)

Complexidade: 
- União: **O(1)** (Segue a função de Ackermann)
- Consulta: **O(1)** (Segue a função de Ackermann)
- Criação: **O(1)** (Sempre)

---

Na teoria de grafos, conjuntos disjuntos são uma pequena mas forte aplicação que auxilia no controle de quantos componentes (nodos ligados/solitários) existem em um grafo. Para isso, se utiliza a implementação de **parentes** (como em uma árvore), onde dois nodos estão em um mesmo componente se seus pais forem os mesmos.

_Nota: Os nodos raízes tem como pai eles mesmos._
Em resumo, a DSU consiste em três funções:

- `unite(int nodo, int alvo)`: Une dois nodos (podendo ser nodo para nodo ou nodo para componente) ligando o novo nodo ao pai do alvo
- `create(int nodo)`: Cria um nodo cujo pai é ele mesmo
- `find(int nodo)`: Encontra o pai do nodo **(a mais vital!)** 

O algoritmo tem o termo "Disjoint" pois cada elemento pertence somente a um agrupamento.

---

### Problema Relacionado e Código do Algoritmo

```cpp
// https://cses.fi/problemset/task/1676

// Contando que os dados são salvos de maneira:
int pai[n];
int tam[n];

// Cria um novo componente
void create(int nodo){
    pai[nodo] = nodo;
    tam[nodo] = 1;
}

// Encontra o pai de um nodo
int find(int nodo){
    if(nodo == pai[nodo]) return nodo;
  return pai[nodo] = find(pai[nodo]); 
  // Retorna o pai E reorganiza a árvore para o melhor caso da DSU
}

int unionDSU(int nodo, int alvo){
    int a = find(nodo);
    int b = find(alvo);

    if(a == b) return; // Já são unidos
    if(tam[a] < tam[b]) swap(a, b); // otimização

    pai[b] = a;
    tam[a] += tam[b];
}
```

**Importante**: É fácil implementar uma variável "qtdComponentes" para guardar quantos elementos separados ainda existem, pois é só decrementá-la para cada união (válida!).