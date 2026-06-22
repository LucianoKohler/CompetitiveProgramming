// https://codeforces.com/group/4QT6JKdRZ8/contest/520029/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    if(s.length() == 1){
        cout << "0\n";
        return;
    }

    char last = '#'; // sentinel
    int qtdSwaps = 0;
    for(char c : s){
        if(c != last){
            qtdSwaps++;
            last = c;
        }
    }
    qtdSwaps--;

    if(
        qtdSwaps%2 == 0 && s[s.length()-1] == '1'
      ||qtdSwaps%2 == 1 && s[s.length()-1] == '0'){
        cout << qtdSwaps;
    }else{
        if(qtdSwaps-1 < 0){
            cout << "0";
        }else{
            cout << qtdSwaps-1;   
        }
    }
    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
