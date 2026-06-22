// https://codeforces.com/problemset/problem/2236/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll a, b, x; cin >> a >> b >> x;

    // The problem has a really limited set of possibilities, so just calculate all of them and do (n²)
    ll divideA[50];
    ll divideB[50];
    divideA[0] = a;
    divideB[0] = b;
    for(int i = 1; i < 50; i++) divideA[i] = divideA[i-1] / x;
    for(int i = 1; i < 50; i++) divideB[i] = divideB[i-1] / x;

    ll mini = LLONG_MAX;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            mini = min(mini, abs(divideA[i]-divideB[j])+i+j);
        }
    }

    cout << mini << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}