# Minimizing Coin Sum

Dado um vetor moedas e uma soma alvo, retorne a quantidade mínima de moedas para atingir tal soma, se ela não for possível, retorne -1

## Estratégia do algoritmo
Usar um vetor "coinsToSumTo" para salvar, para cada soma de 1 a amount, a quantidade mínima de moedas que precisamos para chegar na soma desejada, e, de baixo pra cima, encontrar o resultado óptimo para o problema.

A resolução é iterativa, mas a recursiva é mais bonitinha, envolvendo muito mais DP.

### Problema Relacionado e Código do Algoritmo
- https://cses.fi/problemset/task/1634 (feito em Python)
- https://leetcode.com/problems/coin-change/description/ (feito em CPP)

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coinsToSumTo = [2**32] * (amount+1) # De início, todas as somas são "impossíveis"
        coinsToSumTo[0] = 0 # Mas para chegar em 0, é fácil (caso base)

        for i in range(1, amount+1):
            best = 2**32 # Assumimos que não dá pra chegar na soma
            for coin in coins:
                if i-coin >= 0:
                    # Se encontrarmos que dá à partir de uma soma anterior, tomamos esse valor
                    best = min(coinsToSumTo[i-coin]+1, best) 
            
            # Para chegar em i, precisamos de best moedas
            coinsToSumTo[i] = best

        if coinsToSumTo[amount] == 2**32: return -1
        return coinsToSumTo[amount]
```

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n, targ; cin >> n >> targ;

  ll coins[n];
  vector<ll> coinsToSumTo(targ+1, 10000000);

  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }

  coinsToSumTo[0] = 0;

  for(int i = 1; i < targ+1; i++){
    ll best = 10000000;
    for(ll coin : coins){
      if(i-coin >= 0){
        best = min(best, coinsToSumTo[i-coin]+1);
      }
    }
    coinsToSumTo[i] = best;
  }
  
  if(coinsToSumTo[targ] < 10000000) {
    cout << coinsToSumTo[targ] << endl;
  }else{
    cout << "-1\n";
  }
}
```
