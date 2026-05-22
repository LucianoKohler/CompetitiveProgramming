// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<char>adj[mx];

void solve(){
    string s; cin >> s;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        char a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    int qtdOk = 0;
    for(int i = 0; i < s.size()-1; i++){ // abac
        for(auto ad : adj[s[i]]){
            if(ad == s[i+1]){
                qtdOk++;
                break;
            }
        }
    }

    cout << (qtdOk == s.size()-1 ? "SIM\n" : "NAO\n");

    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
