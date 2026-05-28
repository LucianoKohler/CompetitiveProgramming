# Fibonacci of crazy values

Complexity
- Time: **O(log(n))**
- Memory: **O(1)**

---

Calculating Fibonacci numbers can easily be done in **O(n)** via *Dynamic Programming*, but when neeidng to calculate astronomical values such as **F(10^18)**, the algorithm won't cut. Worry not, for matrix representation is here!

Since the Fibonacci series is a **linear regression** (it's values are generated with and only with its own values from past calculations), we can represent this regression as a **matrix** as follows:

```
T = | 1 1 |
    | 1 0 |
```

The Transition Matrix **T**, when elevated to the power of **N**, generates the **F(N)** on its `[1][1]` slot, because of that, the only thing that's left for us is to efficiently elevate this matrix to **N**, which can trivially be done via **binary exponentiation**!!!

# Code

```cpp
// https://cses.fi/problemset/task/1722 -> Related problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
ll T[2][2] = {{1, 1},{1, 0}}; // Transition 
ll E[2][2] = {{1, 1}, {1, 0}}; // Exp (transition's auxiliary)

// Usual matrix multiplying
void multiply(ll A[2][2], ll B[2][2], ll mod){
    ll a = (((A[0][0] * B[0][0]) % mod) + ((A[0][1] * B[0][1]) % mod)) % mod;
    ll b = (((A[0][0] * B[1][0]) % mod) + ((A[0][1] * B[1][1]) % mod)) % mod;
    ll c = (((A[1][0] * B[0][0]) % mod) + ((A[1][1] * B[0][1]) % mod)) % mod;
    ll d = (((A[1][0] * B[1][0]) % mod) + ((A[1][1] * B[1][1]) % mod)) % mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;

    return;
}

ll fib(ll n, ll mod){

    // Calculate T^n with binary exponentiation approach
    while(n){
        if(n%2 == 1) multiply(T, E, mod);
        multiply(E, E, mod);
        
        n>>=1;
    }

    // cout << T[0][0] << " " << T[0][1] << "\n";
    // cout << T[1][0] << " " << T[1][1] << "\n";

    return T[1][1];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n; cin >> n;

    cout << fib(n, modulo) << "\n";

    return 0;
}
```

# Reduced version
```cpp
ll T[2][2] = {{1, 1},{1, 0}};  
ll E[2][2] = {{1, 1}, {1, 0}}; 

void multiply(ll A[2][2], ll B[2][2], ll mod){
    ll a = (((A[0][0] * B[0][0]) % mod) + ((A[0][1] * B[0][1]) % mod)) % mod;
    ll b = (((A[0][0] * B[1][0]) % mod) + ((A[0][1] * B[1][1]) % mod)) % mod;
    ll c = (((A[1][0] * B[0][0]) % mod) + ((A[1][1] * B[0][1]) % mod)) % mod;
    ll d = (((A[1][0] * B[1][0]) % mod) + ((A[1][1] * B[1][1]) % mod)) % mod;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;

    return;
}

ll fib(ll n, ll mod){
    while(n){
        if(n%2 == 1) multiply(T, E, mod);
        multiply(E, E, mod);

        n>>=1;
    }
    return T[1][1];
}
```