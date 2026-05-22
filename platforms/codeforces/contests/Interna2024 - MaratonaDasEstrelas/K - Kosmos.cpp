// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/K
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 998244353;
const int mx = 2e5+5;

ll exp(ll base, ll exp, ll mod){
    exp %= mod;
    if(exp == 0) return 1;

    ll ans = 1;
    ll aux = base;

    while(exp){
        if(exp & 1) ans *= aux % mod;
        aux *= aux % mod;
        ans %= mod;
        aux %= mod;
        exp = exp >> 1;
    }
    return ans;
}

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

void solve(){
    ll n; cin >> n;
    ll exponent = fib(n, modulo-1); // mod-1 for fermat's little theorem

    cout << exp(2, exponent, modulo) << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
