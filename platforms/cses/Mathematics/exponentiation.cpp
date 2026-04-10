#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

ll exp(ll base, ll exp){
    exp %= modulo;
    if(exp == 0) return 1;

    ll ans = 1;
    ll aux = base;
    // 13 = 8 + 4 + 1
    //13 -> 1101

    while(exp){
        if(exp & 1) ans *= aux % modulo;
        aux *= aux % modulo;
        ans %= modulo;
        aux %= modulo;
        exp = exp >> 1;
    }
    return ans;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        cout << exp(a, b) << "\n";
    }
    return 0;
}
