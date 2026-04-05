**_Documento usado para compilar todos os códigos úteis em um único documento para acesso rápido via tags (usando ctrl+F)_**

# Dicas gerais

- Sempre notar se há um padrão nos outputs (a - b, a \* b...), **principalmente nos problemas fáceis**
- Sempre analise a fórmula dada, talvez dê para simplificá-la

- Loops de 0 a N em
  - **C/C++:** `while(n--){}`
  - **Python:** `for _ in range(n):`

# Algoritmos:

**Ceil:**

```cpp
(a + b - 1) / b
```

_tags: optimization, data types, ceiling, rounding, math_

---

**Primo:**

```cpp
bool isPrime(int num) {
      if(num <= 1) return false;
      if (num <= 3)  return true;

      // This is checked so that we can skip
      // middle five numbers in below loop
      if (num % 2 == 0 || num % 3 == 0)
          return false;


      for (int i = 5; i <= sqrt(num); i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;

      return true;
  }
  // Copied from Apurba Roy in Stack Overflow
```

_tags: optmization, prime numbers, math, complexity_

---

**Inputting Lines and Words:**
```cpp
int main() 
{
    char c;
    char word[20];
    char sen[100];
    
    scanf("%c", &c); // Read char
    scanf("%s", word); // Read string
    scanf("\n"); // Skip the blank line so line below does not break
    scanf("%[^\n]%*c", sen); // Reads the entire line
    
    printf("%c\n", c);
    printf("%s\n", word);
    printf("%s\n", sen);
    return 0;
}
```

_tags: input, scanf, string_

---

**Output Formatting:**

```cpp
int main() {
  // Strings with always X characters
  char s[6] = "string";
  printf("%10s\n", s); // Align right
  printf("%-10s\n", s); // Align left

  // Numbers with always X digits
  int num = 2;
  printf("%09d\n", num); // Places var at the end (000000002)

  return 0;
}
```
_tags:  output, formatting, printf, string, int_

---

```cpp
// Forma otimizada de elevar a^n
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

# Quando usar unsigned long long?
- O problema envolve uma soma que passe de 10^18
- Riscos de overflow


