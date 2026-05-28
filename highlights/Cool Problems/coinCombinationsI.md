# Coin Combinations I
Dado um vetor **moedas** e um valor **alvo**, retorne de quantas formas possíveis é possível gerar aquela soma com as moedas à disposição

## Estratégia do algoritmo
Usamos um vetor memo (dp) para salvar cálculos já feitos para evitar uma recursão agressiva, construindo a soma total do alvo até os casos base:
- Se a soma for 0, temos uma forma de gerar 0: { }
- Se a soma for menor que 0, desconsideramos o caso
- Caso contrário, checamos a dp e retornamos o valor calculado recursivamente

### Problema Relacionado e Código do Algoritmo

```cpp
// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const ll MAXN = 1e6+7;

vector<ll>memo(MAXN, -1);
vector<ll>coins;

/* How many ways can we get to sum?*/
int howManyWaysToGetTo(int n){

  // Base cases
  if(n == 0) return 1;
  if(n < 0) return 0;
  if(memo[n] != -1) return memo[n]; // DP

  ll ways = 0;

  // Recursion for each coin
  for(auto coin : coins){
    ways += howManyWaysToGetTo(n-coin) % modulo;
  }

  // Memoize the value for future use
  memo[n] = ways % modulo;
  return ways % modulo;
}

int main(){
  memo[0] = 1; // 1 way to get to sum 0: { }
  int n, target; cin >> n >> target;

  for(int i = 0; i < n; i++){
    int coin;
    cin >> coin;
    coins.push_back(coin);
  } 

  cout << howManyWaysToGetTo(target) << endl;

  return 0;
}
```