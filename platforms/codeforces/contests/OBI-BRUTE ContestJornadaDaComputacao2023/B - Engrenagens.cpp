// https://codeforces.com/group/4QT6JKdRZ8/contest/473126/problem/B  
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll>gears(n+1, 0);
    ll offsetPares = 0;
    ll offsetImpares = 0;

    for(ll i = 1; i <= n; i++) cin >> gears[i];

    while(q--){
        ll type; cin >> type;
        if(type == 1){
            ll num; cin >> num;
            if(num % 2 == 1){
                offsetImpares += gears[num];
                offsetPares -= gears[num];
            }else{
                offsetImpares -= gears[num];
                offsetPares += gears[num];
            }
        }else{
            ll num; cin >> num;
            if(num % 2 == 1){
                int ans = (gears[num] + offsetImpares) % gears[num];
                if(ans < 0) ans += gears[num]; // Negative: we sum modulo
                cout << ans << "\n";
            }else{
                int ans = (gears[num] + offsetPares) % gears[num];
                if(ans < 0) ans += gears[num]; // Negative: we sum modulo
                cout << ans << "\n";
            }
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}