// https://codeforces.com/group/4QT6JKdRZ8/contest/612670/problem/D      
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    string s; cin >> s;
    char c; cin >> c;

    bool can = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c){
            if(i % 2 == 0){
                can = true;
                break;
            }
        }
    }

    cout << (can ? "YES\n" : "NO\n");
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
