#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

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

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        ll a, b, c; cin >> a >> b >> c;
        ll pBC = exp(b, c, modulo-1);
        
        cout << exp(a, pBC, modulo) << "\n";
    }
    return 0;
}
