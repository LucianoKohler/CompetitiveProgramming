// https://codeforces.com/gym/106601/problem/H
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

/* Consider that all dinossaurs are attacking us at the start, we need to tame 
the dinossaurs that maximize the relation between giving us power and weakening 
the attackers, to do so, we can choose the dinossaurs with the highest sum of 
power and weaknesses, because i know that by choosing him, I will increase my power
along with weakening the other side optimally */

void solve(){
    int n; cin >> n;
    vector<array<ll, 3>>a;
    ll enemyPower = 0;
    ll myPower = 0;
    for(int i = 0; i < 2*n; i++){
        ll p, d; cin >> p >> d;
        enemyPower+= d;
        a.push_back({p+d, p, d});
    }

    sort(a.begin(), a.end(), greater<>());

    for(int i = 0; i < n; i++){
        enemyPower -= a[i][2];
        myPower += a[i][1];
    }

    cout << myPower - enemyPower << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}