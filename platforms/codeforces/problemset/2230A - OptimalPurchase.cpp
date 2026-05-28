#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, s, g; cin >> n >> s >> g;
    ll sum;
    if(3*s < g){ // Just buy single keys
        sum = n*s;
    }else{
        sum = (n/3)*g;

        // See the rest
        if(n%3*s < g){ // singles
            sum += n%3 * s;
        }else{ // group
            sum += g;
        }
    }
    cout << sum << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
