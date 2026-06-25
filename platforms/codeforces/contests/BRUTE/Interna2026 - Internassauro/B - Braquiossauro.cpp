// https://codeforces.com/gym/106601/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int h, a, b; cin >> h >> a >> b;
    if(h >= a && h <= b) cout << "SIM\n";
    else cout << "NAO\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}