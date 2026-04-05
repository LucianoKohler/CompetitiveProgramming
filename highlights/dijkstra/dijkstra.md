# Dijkstra

Complexidade: 
- Processamento: **O((N + M) * log N)**
- Memória: **O(N + M)**

_Sendo **N** a quantidade de nodos e **M** a quantidade de arestas_

---

_Nota: É recomendado ver uma exemplificação prática do que é um algoritmo de caminho mínimo, para isso, [Esse vídeo me ajudou de monte](https://www.youtube.com/watch?v=EFg3u_E6eHU&t=384s)_.

Na implementação de grafos, Dijkstra é um **algoritmo que procura um caminho mínimo** entre um nodo A para um nodo B quando os nodos possuem peso.

Sua implementação é muito mais entendível quando vista visualmente, mas em resumo, dado um conjunto de:
* Nodos (como por exemplo, cidades ou localidades)
* Arestas pesadas (como or exemplo, o tempo de viagem da cidade A para a B)

Podemos encontrar uma rota otimizada por meio da criação de um vetor de _distâncias de A_ que, de aresta em aresta, vai dizendo o custo mínimo que levaria para ir do ponto A ao ponto X (não necessariamente o nodo alvo B)

Tome de exemplo este grafo direcionado e ponderado:

![Grafo visualmente](graph.png)

Se iniciarmos do nodo 1, temos a tabela de _distâncias de 1_, que indica a distância de cada nodo em relação ao nodo 1:

| Nodo | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|
|------|---|---|---|---|---|---|---|---|---|---|
| Dist | 0 | 5 | 9 | 18| 22| 10| 14| 23| 27|31 |


Pequenas implementações são utilizadas para o algoritmo, como **Filas de Prioridade** para otimizar a escolha de arestas (optando pelas mais baratas primeiro) e duas matrizes: de **adjacência** e de **distância**:


```cpp

// Assumindo uma arquitetura de adjacências do tipo:
vector<pair<ll, int>>adj[n];
vector<ll>dist(n,inf);

/* EXEMPLO 
adj[1] = {(6, 2), (2, 3), (4, 3)}
adj[2] = {}
adj[3] = {(3, 2)}
Onde cada par é um voo do tipo (tempo de voo, destino)
*/

void dijkstra(int inicial, int final){
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    // Para indicar à pq que a ordem é do menor para o maior, precisamos passar esse segundo parâmetro obrigatoriamente

    pq.emplace(0, inicial);
    while(!pq.empty()){
        auto [custo, atual] = pq.top();
        pq.pop();

        if(minDist[atual] != custo) continue;
        // Se for encontrada outra forma de se chegar no nodo, pula, pois pela natureza da pq, a primeira aresta já será a melhor por ser a de menor custo

        for(auto [tempo, destino] : adj[atual]){
            if(custo + tempo < minDist[destino]){
                // Otimização encontrada!
                minDist[destino] = custo + tempo;
                pq.emplace(minDist[destino], destino);
            }
        }
    }
}

// Nota: há um código com um problema implementado no arquivo dijkstra.cpp para viualizar as declarações e setups.
```