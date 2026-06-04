// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, x; cin >> n >> x;

    for(int i = 2; i <= n; i++){
        if(i%x == 0){
            continue;
        }
        cout << n*i << "\n";
        break;
    }
    
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}