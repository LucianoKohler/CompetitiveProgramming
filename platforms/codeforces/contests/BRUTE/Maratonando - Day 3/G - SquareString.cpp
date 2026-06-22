// https://codeforces.com/group/4QT6JKdRZ8/contest/518512/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    string s; cin >> s;
    if(s.size() % 2 == 1){
        cout <<"NO\n";
        return;
    }

    bool isSquare = true;
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[i+s.size()/2]) isSquare = false; 
    }

    cout << (isSquare ? "YES\n" : "NO\n");
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}