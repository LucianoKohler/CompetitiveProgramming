// https://codeforces.com/problemset/problem/1843/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n; cin >> n;
    ll sum = 0;

    sum += n;
    while(n > 1){
        sum += n/2;
        n/=2;
    }

    cout << sum << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}