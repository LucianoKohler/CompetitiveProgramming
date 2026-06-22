// https://codeforces.com/problemset/problem/2236/B 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    for(int i = 0; i < n-k; i++){
        if(s[i] == '1'){
            s[i] = '0';
            if(s[i+k] == '0') s[i+k] = '1';
            else              s[i+k] = '0';
        }
    }

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}