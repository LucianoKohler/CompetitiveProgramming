// https://codeforces.com/problemset/problem/2231/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cout << 2*n - i << " ";
    }

    cout << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
