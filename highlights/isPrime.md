# Is Prime

Complexidade: 
- Processamento: **O(sqrt(n))**
- Memória: **O(1)**

---

A função de cálculo de primos otimizada utiliza o esqueleto padrão de verificação, porém, contendo várias otimizações e uso de teoremas para torná-la mais rápida, como por exemplo:
- Verificamos os valores iniciais para iniciar o for mais longe
- Se verificamos o % de 2 e 3, podemos pular de 6 em 6 no for
- Não precisamos loopar até n, mas sim até sqrt(n)

Assim, tornando a função muito mais elegante e otimizada.

*Nota: Para calcular vários valores pequenos, é melhor o uso do **Crivo de Eratóstenes (DP)**, mas na maioria dos casos, essa função já supre*

```cpp
bool isPrime(int num) {
      // Corner cases
      if(num <= 1) return false;
      if (num <= 3)  return true;

      // Testados para que o for seja mais ágil
      if (num % 2 == 0 || num % 3 == 0)
          return false;

      // Várias mini otimizações acontecem aqui graças às verificações anteriores
      for (int i = 5; i <= sqrt(num); i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;

      return true;
  }
  ```