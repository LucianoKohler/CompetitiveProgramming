// Problema relacionado: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 1e5+3; // Limite de x
const ll inf = 1e18; // Valor "infinito" para encher o vetor de distâncias

vector<pair<ll, int>>adj[mx];
vector<ll>dist(mx,inf);

/*
adj[1] = {(6, 2), (2, 3), (4, 3)}
adj[2] = {}
adj[3] = {(3, 2)}
Onde cada par é um voo do tipo (tempo de voo, destino)
*/

void dijkstra(int inicial, int final){
    // Para indicar à pq que a ordem é do menor para o maior, precisamos passar esse segundo parâmetro obrigatoriamente
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, inicial);
    while(!pq.empty()){
        auto [custo, atual] = pq.top();
        pq.pop();

        // Se for encontrada outra forma de se chegar no nodo, pula, pois pela natureza da pq, a primeira aresta já será a melhor por ser a de menor custo
        if(dist[atual] != custo) continue;

        for(auto [tempo, destino] : adj[atual]){
            if(custo + tempo < dist[destino]){
                dist[destino] = custo + tempo;
                pq.emplace(dist[destino], destino);
            }
        }
    }
}

int main(){
    
    cout << "Insira o input padronizado (o fim do codigo tem um): ";
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        // Cidade inicial, cidade final, custo de viagem
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    int inicial = 1;
    int alvo = 1;

    cout << "Insira os nodos de inicio e chegada: ";
    cin >> inicial >> alvo;

    dist[inicial] = 0;

    dijkstra(inicial, alvo);
    cout << "Custo para chegar ao destino: " << dist[alvo] << " ";
}

/* Input válido para o problema:
10 16
7 5 8
5 1 8
7 8 9
4 5 8
6 7 4
5 6 3
9 10 9
10 6 4
10 9 9
2 3 4
10 5 9
1 2 5
9 8 3
3 4 9
4 9 9
3 6 1

*/
