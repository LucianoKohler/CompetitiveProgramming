# Inclusion-Exclusion Principle

### Introduction
To explain this problem better, I will be using as a basis, the CSES problem **[Christmas Party](https://cses.fi/problemset/task/1717/)**

The **Inclusion-Exclusion Principle** is a fundamental knowledge to solve combinatorics problems that often involve *"finding how many ways something is possible"*. 

### Problem Approach

As a starting point, lots of answers to combinatorics follow the pattern **Answer = total states - wrong states**, this problem is not an exception, and with a small deduction, we can point that the total states that the presents can be distributed is **n!**.

Now, to find the wrong states, we can use a **set of rules** to find these cases:

`R = {R1, R2, R3, ..., Rn}`

Where **Ri** = cases that **suffice condition i**, the condition, in this case, being **"kid i has the present of kid i"**

These sets can be easily calculated by assuming one present will be fixed while the other ones will permute, therefore, **Ri = (n-1)!**. Now that we know that, the answer to the problem is trivial:

**Answer = n!   -   |R1 ∪ R2 ∪ R3 ∪ ... ∪ Rn|**

Union assures that **cases won't overlap**, so the answer will be right for every input. But now... How do we implement union in C++??

The answer is: **We don't!** It is too expensive to make, we are better using the protagonist of this document: The **Inclusion-Exclusion Principle!!!**

### Algorithm's Usefulness
---

<center><i>From this point onwards, assume n = 3</i></center>

---

The Inclusion-Exclusion Principle says that, if we just add the values of R1, R2 and R3 (just that because n = 3), we will be unevitably summing the values of the sets `{R1, R2}`, `{R2, R3}` and `{R1, R3}` twice, and the set `{R1, R2, R3}` thrice!!!

We can easily fix that by subtracting the value of the sets `{R1, R2}`, `{R2, R3}` and `{R1, R3}`, but since `{R1, R2, R3}` is included in all of them, we also excluded the case where all presents are in a wrong order three times, eliminating these cases!!!

To fix that **AGAIN**, we just sum the value of `{R1, R2, R3}` to the sum, so on and so forth.

Did you notice the pattern? We can safely calculate the union of N sets that overlap by **summing odd sized sets** and **subtracting even sized sets**.

Finally, we can calculate `{R1, ..., Ri}` trivially via binomial coeficients **(n choose k)**, and then multiplying the result by **(n - k)!**, where **k** is the number of locked presents.

### Problem's Resolution

Again, this algorithm solves CSES' "Christmas Party" problem.

```cpp
// https://cses.fi/problemset/task/1717/        
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1e6+5; // This varies!

ll fat[mx];
ll invFat[mx];

ll binExp(ll a, ll b){
    ll ans = 1;
    
    while(b){
        if(b & 1) ans = (ans * a) % modulo; 
        a = (a*a) % modulo;
        b >>= 1;
    }

    return ans;
}

void preCalcFactorial(ll n){
    fat[0] = 1;
    fat[1] = 1;
    
    // Calculate fats
    ll ans = 1;
    for(int i = 2; i <= n; i++){
        ans = (ans * i) % modulo;
        fat[i] = ans;
    }

    // Calculate invFats (note that i/i! = invFat[i-1])
    invFat[n] = binExp(fat[n], modulo-2);
    for(int i = n; i > 0; i--){
        invFat[i-1] = (i * invFat[i]) % modulo;
    }
}

ll binCoef(ll n, ll k){ // nCk (n choose k)
    ll ans = (fat[n] * invFat[k]) % modulo;
    ans = (ans * invFat[n-k]) % modulo;
    return ans;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    // Pre-calculate all factorials and inverses
    preCalcFactorial(mx); 

    int n; cin >> n;
    ll badCases = 0;

    for(int i = 1; i <= n; i++){
        ll aux = (binCoef(n, i) * fat[n-i]) % modulo;
        if(i%2==1){
            badCases = (badCases + aux) % modulo;
        }else{
            badCases = (badCases - aux) % modulo;
        }
    }

    cout << (fat[n] - badCases) % modulo << endl;
    return 0;
}
```



