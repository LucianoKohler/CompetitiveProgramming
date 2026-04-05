# Is Palindrome

Complexidade: 
- Processamento: **O(n/2)** 
- Memória: **O(1)**

---

A função usa *sliding windows* para verificar se o primeiro caractere é igual ao último, em seguida, puxa ambos os índices mais para dentro da string e assim por diante

```cpp
int isPalindrome(string s){
  int l = 0;
  int r = s.length()-1;
  while(l < r){
    if(s[l] == s[r]){
      l++;
      r--;
    }else{
      return 0;
    }
  }

  return 1;
}
```