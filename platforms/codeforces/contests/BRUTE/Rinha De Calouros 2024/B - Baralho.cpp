// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/B   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, qtd; cin >> n >> qtd;
    vector<int>qtdCards(qtd, 0);

    
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        qtdCards[v-1]++;
    }

    if(qtd == 1 || n == 1){
        cout << 0 << "\n";
        return;
    }

    sort(qtdCards.begin(), qtdCards.end(), greater<>());

    cout << n - qtdCards[0] << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}