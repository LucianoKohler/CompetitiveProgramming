// https://cses.fi/problemset/task/2216/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    map<int, int>m;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        m[a] = i;
    }
    
    // for(int i = 1; i <= n; i++) cout << m[i] << " ";

    int rounds = 1;
    for(int i = n; i >= 2; i--){
        if(m[i] < m[i-1]){
            rounds++;
        }
    }
    cout << rounds << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
