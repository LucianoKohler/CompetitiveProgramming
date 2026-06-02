// https://codeforces.com/problemset/problem/2204/A  
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int qtdReceived = 0;
    int i = 0;
    if(s == "R"){
        cout << "1\n";
        return;
    }
    while(i < n && s[i] == 'R'){
        i++;
        qtdReceived++;
    }
    
    cout << qtdReceived+1 << "\n";
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
