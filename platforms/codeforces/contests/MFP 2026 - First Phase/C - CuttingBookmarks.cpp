// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int x, y; cin >> x >> y;

    ll vertical = x * (y/7);
    ll horizontal = (x/7) * y;

    cout << max(vertical, horizontal) << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
