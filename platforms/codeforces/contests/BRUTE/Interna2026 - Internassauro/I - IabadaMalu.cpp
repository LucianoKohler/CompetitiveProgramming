// https://codeforces.com/gym/106601/problem/I
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    string s = "";
    while(n > 9){
        s+= '9';
        n -= 9;
    }

    cout << n << s << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}