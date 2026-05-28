// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n; cin >> n;
    cout << (n%3 == 0 ? "PERDE" : "GANHA");
    return;
}

/*
Bullshit pra resolver o problema:
Dado um jogo de remover p^k de um número n (p precisa ser primo)
se n%p+1 == 0, o jogador 1 sempre perde.

nesse caso, p = 2, e se n fosse 30, 30%(2+1) = 0, logo o jogador
1 perde se n = 30
*/

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
