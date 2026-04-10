#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1e6+5; // This varies!

/*
We can't do divisions in modular arithmetic, to do so, we need the modular inverse, since
multiplying by the inverse of a number implies dividing the number by such number.

having mod = 1e9+7 and a = 5, for example, by Fermat's Little Theorem, the modular inverse 
of a equals 5 * 5^(1e9+5) ( = 1 )

We'll use binExp to get that crazy number
*/

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

    // Calculate invFats
    invFat[n] = binExp(fat[n], modulo-2);
    for(int i = n; i > 0; i--){
        invFat[i-1] = (i * invFat[i]) % modulo;
    }
}

/*
invFat[i] = 1/i!
invFat[i-1] = i/i!

*/

ll binCoef(ll n, ll k){
    /*
        n!
    k! * (n-k)!
    */

    ll ans = (fat[n] * invFat[k]) % modulo;
    ans = (ans * invFat[n-k]) % modulo;
    return ans;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    // Pre-calculate all factorials and inverses
    preCalcFactorial(mx);

    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        cout << binCoef(a, b)  << "\n";
    }
    return 0;
}
