// https://codeforces.com/group/4QT6JKdRZ8/contest/473126/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int bra, arg; cin >> bra >> arg;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a; cin >> a;
        if(a == 'A') arg++;
        else bra++;
    }

    if(bra == arg){
        cout << "EMPATE\n";
        return;
    }

    cout << (bra > arg ? "BRASIL\n" : "ARGENTINA\n");
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}