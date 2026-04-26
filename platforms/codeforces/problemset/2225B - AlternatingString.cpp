// https://codeforces.com/problemset/problem/2225/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int qtdDupes = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]) qtdDupes++;
        }

        if(qtdDupes >= 3){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}