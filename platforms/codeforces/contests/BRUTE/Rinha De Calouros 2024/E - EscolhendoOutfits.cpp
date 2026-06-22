// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/E    
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    double n; cin >> n;
    cout << (ll)(floor(n/2) * ceil(n/2)) << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}