// https://codeforces.com/gym/106601/problem/N
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>a(n, 0);

    for(auto &it : a) cin >> it;

    int qtd = 0;
    for(int i = 1; i < n-1; i++) if(a[i-1] < a[i] && a[i+1] < a[i]) qtd++;
    cout << qtd << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}