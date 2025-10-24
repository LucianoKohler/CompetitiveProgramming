# Prefix sum

Complexidade: 
- Construção: **O(n)**
- Consulta: **O(1)**
- Memória: **O(n)**

---

Dado um array de valores estático (seus elementos não mudam) de exemplo: 
`nums[n] = { 3, 2, 4, 5, 1, 1, 5, 3 }`

Se queremos saber a soma dos valores entre "a" e "b", podemos fazer, para cada soma, um laço de repetição que passa pelos valores e soma os valores em uma variável acumuladora. Essa solução é O(N²), e quebra nos casos absurdos, é então, que o **prefix sum** entra em cena.

Para cada valor lido, temos um outro array "sum" que salva a soma de todos os valores de 0 a n, veja o exemplo:

| nums | 3 | 2 | 4 | 5  | 1  | 1  | 5  | 3  |
|------|---|---|---|----|----|----|----|----|
| sum  | 3 | 5 | 9 | 14 | 15 | 16 | 21 | 24 |

Assim, para conceber a soma do intervalo a até b, podemos simplesmente retornar **sum[b-1] - sum[a-2]**, elegantemente de forma O(1).

### Problema Relacionado e Código do Algoritmo
```cpp
// https://cses.fi/problemset/1646/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int tam, queries; // T
    cin >> tam >> queries;
    ll nums[tam];
    ll sum[tam];

    for(int i = 0; i < tam; i++){
        cin >> nums[i];
        if(i==0){
          sum[i] = nums[i];
        }else{
          sum[i] = sum[i-1] + nums[i];
        }
    }
    
    while(queries--){
        int a, b; // Retornar soma de "a" até "b"
        cin >> a >> b;
        if (a == 1){
          cout << sum[b-1] << endl;
        }else{
          cout << sum[b-1] - sum[a-2] << endl;
        }
    }
 
    return 0;
}
```