// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/D   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, d; cin >> n >> d;
    if(d%2 == 1 || d == 1){
        cout << n << "\n";
        return;
    }

    cout << n-(n/(d+1));

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}