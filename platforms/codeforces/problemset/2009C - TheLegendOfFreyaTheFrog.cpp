// https://codeforces.com/problemset/problem/2009/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    double x, y, k; cin >> x >> y >> k;
    ll qtdXjumps = ceil(x/k);
    ll qtdYjumps = ceil(y/k);
    
    // We need to account waiting moves (if we reached target x but not target y for example)
    ll waitingMoves = max(qtdXjumps, qtdYjumps) - min(qtdXjumps, qtdYjumps);

    if(qtdXjumps > qtdYjumps) waitingMoves--;

    cout << qtdXjumps + qtdYjumps + waitingMoves << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

