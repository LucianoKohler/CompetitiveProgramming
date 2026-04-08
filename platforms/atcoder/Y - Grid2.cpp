#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

ll fat(int n){
    ll num = 1;
    for(int i = 2; i <= n; i++){
        num *= i;
    }

    return num;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll h, w, n; cin >> h >> w >> n;
    // Get obstacles

    ll total = ((h-1)*(w-1)) % modulo;
    return 0;
}

/*

SUB-PROBLEMA
na grid andamos w-1 pra direita e h-1 pra baixo, 
podemos simplificar em bolinhas, onde bolinha pintada = andar pra direita 

tenho i bolinhas, de quantas formas eu posso pegar j bolinhas?

dp[i][j] = "de quantas formas eu posso pegar j bolinhas dentre i bolinhas?"
fazendo DP jogando pra frente

dp[i+1][j] += valor
dp[i+1][j+1] += valor

Isso é o triângulo de pascal (!!!)

E tudo isso pra dizer que não pode fazer a DP pq 1e5 * 1e5 dá TLE

Só usar a fórmula de permutação

p =    n! dividido pela repetição de direitas vezes repetição de baixos

no nosso caso,
p = ((w-1)*(h-1))!
    (w-1)!*(h-1)!

VOLTANDO AO PROBLEMA

ideia geral: pra cada obstáculo, calculamos quantos
caminhos temos do obstáculo anterior até o próximo
obstáculo, e removemos ele do valor final

mult *= a
mult %= mod
mult += mod
mult %= mod

O menor valor que ax + by pode ter (Com x e y arbitrários) é gcd(a, b)
^- bézout identity

INVERSO MODULAR 
sendo 3 e 4 adotados
3 * 3^-1 = 1 (mod 4)
3^-1 = 3, pois 3 * 3 = 9 que mod 4 = 1 (crazy)

Teorema de 

p = valor do mod
a = nosso n
a^(p-1) = a ^(p-2)

mas p-2 = 1e9 + 5 (crazy)

exponenciação binária entra em cena
*/