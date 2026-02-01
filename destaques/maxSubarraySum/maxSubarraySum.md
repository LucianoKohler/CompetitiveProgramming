# Contexto do problema

Dado um array de valores positivos ou negativos, encontre o subarray dentro desse array com a maior soma possível

Exemplo:

`nums = [-2,1,-3,4,-1,2,1,-5,4]`

Aqui, a melhor soma é **6**
Pois o sbubarray `[4, -1, 2, 1]` tem a maior soma de todos os subarrays de nums

---

Mesmo que esse problema não ensine nada muito importante, esse caso é especial pois, mesmo que o problema seja facilmente resolvido em **O(n³)**, é possível otimizar o código para chegar em um approach **O(n²)** e até mesmo **O(n)**!

# Approach O(n³)

Sem segredo, resolver o problema em O(n³) chega a ser trivial, em resumo, testamos TODAS as possibilidades de somar um mesmo array, garantino a soma maior somente testando todas as possibilidades diferentes:

```cpp
int solve(vector<int>& nums){
    int size = nums.size();
    int best = 0, sum = 0;
    
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            for(int k = i; k <= j; k++){
                sum+=nums[k];
                best = max(best, sum);
            }
            sum = 0;
        }
    }

    return best;
}
```

# Approach O(n²)

É fácil otimizar o código para chegar em O(n²), visto que todas as possiblidades de somas já são percorridas com dois for aninhados, remanejando o código, temos:

```cpp
int solve(vector<int>& nums){
    int size = nums.size();
    int best = 0, sum = 0;
    
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            sum+=nums[j];
            best = max(best, sum);
        }
        sum = 0;
    }

    return best;
}
```

# Approach O(n)
A forma de tornar o código O(n) é **genial**! Percorremos o array apenas uma vez, e a cada iteração, *fazemos uma pergunta*:

*"Vale a pena eu continuar somando os valores que eu tenho até agora com esse novo, ou eu **largo tudo** e começo desse aqui?"*

Essa resposta é respondida comparando a soma atual com o novo valor comparado, e se esse novo valor analisado for maior do que a nossa soma, significa que é mais vantajoso para nós **largarmos a soma** que estávamos construindo para **iniciar desse novo valor** que, pela comparação feita, é grande o suficiente para ser membro da maior soma.

Essa linha de raciocínio foi descoberta e nomeada em cima de seu autor: **Kadane**

REMANEJANDO DE NOVO:

```cpp
int solve(vector<int>& nums){ // Algoritmo de Kadane
    int size = nums.size();
    int best = 0, sum = 0;
    for (int i = 0; i < size; i++) {
    sum = max(nums[i],sum+nums[i]); // Essa é a pergunta feita na explicação!!
    best = max(best,sum);
    }
    
    return best;
}
```