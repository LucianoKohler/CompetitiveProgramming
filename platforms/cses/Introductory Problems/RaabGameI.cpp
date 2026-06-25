// https://cses.fi/problemset/task/3399
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, losses, wins; cin >> n >> losses >> wins;
    int ties = n-losses-wins;
    vector<int>a(n+1, 0);
    vector<int>b(n+1, 0);

    if(ties < 0 || wins == n || losses == n){ 
        cout << "NO\n";
        return;
    }

    n -= ties;

    // Wins & losses
    for(int i = 1; i <= n; i++){
        a[i] = i;
        b[i] = i+losses;
        if(b[i] > n){
            b[i] -= n;
        }
    } 

    // Draws
    for(int i = n+1; i <= n+ties; i++){
        a[i] = i;
        b[i] = i;
    }

    // Simulating just to be sure
    int Swins = 0, Slosses = 0, Sties = 0;
    for(int i = 1; i <= n+ties; i++){
             if(a[i] == b[i]) Sties++;
        else if(a[i] < b[i])  Swins++;
        else                  Slosses++;
    }

    if(wins == Swins && losses == Slosses && ties == Sties){
        cout << "YES\n";
        for(int i = 1; i <= n+ties; i++){ cout << a[i] << " "; }
        cout << "\n";
        for(int i = 1; i <= n+ties; i++){ cout << b[i] << " "; }
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}

/*
assume 5
b = 4 wins (+1)
1 2
2 3
3 4
4 5
5 1

b = 3 wins (+2)
1 3
2 4
3 5
4 1
5 2

b = n-T
1 (1+T)
2 (2+T)
3 (3+T)
4 (4+T)
5 (5+T)

and if num + T > n, -= n
*/

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

/*
---
1 2 3 4 -> 2 wins
1 2 3 4 -> 1 win

draws -> losses -> wins
1 2 3 4
1 4 2 3
---



 



 

*/