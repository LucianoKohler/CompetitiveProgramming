# Binary Exponentiation

Complexity
- Time: **O(log(n))**
- Memory: **O(1)**

---

It is known that a number in the form of **aᵇ** can be expressed by **a * a * a * ... b times**, this is totally doable in code, but when we need to calculate potencies of humongous numbers, the time complexity of **O(n)** won't cut.

For that case, we can **binary exponentiate** the number! How does that work? It's super simple! Imagine the number:

<center><b>5²⁸</b></center>

this guy, according to exponentiation properties, is the same as

<center><b>5¹⁶ * 5⁸ * 5²</b></center>

Since we can express an exponent as a **multiplication of smaller exponents**. With that in mind, we know that binary can represent **every integer number**, so we can express **aᵇ** as a multiplication of a to values that represent bits in a number.

Note that in the above example, we multiplied 5 elevated to powers of 2, but not all of them, that is because **28** is expressed as **11010**, so we chose to multiply by **2, 8 and 16**, we can do that easily in code by keeping track of which potency is currently being multiplied with an **auxiliary variable** 

---

# Code

```cpp
// https://cses.fi/problemset/task/1095 -> related problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;

ll exp(ll base, ll exp){
    exp %= modulo;
    if(exp == 0) return 1;

    ll ans = 1;
    ll aux = base;
    // 13 = 8 + 4 + 1
    // 13 -> 1101

    while(exp){
        // If this bit is on, multiply by the auxiliary
        if(exp & 1) ans = (ans * aux) % modulo;
        // Always multiply the auxiliary
        aux = (aux * aux) % modulo;

        exp >>= 1;
    }
    return ans;
}
```

# Reduced version
```cpp
ll exp(ll base, ll exp){
    exp %= modulo;
    if(exp == 0) return 1;

    ll ans = 1;
    ll aux = base;

    while(exp){
        if(exp & 1) ans = (ans * aux) % modulo;
        aux = (aux * aux) % modulo;
        exp >>= 1;
    }
    return ans;
}
```