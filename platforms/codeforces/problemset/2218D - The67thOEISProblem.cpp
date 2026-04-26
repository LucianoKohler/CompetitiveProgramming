// https://codeforces.com/problemset/problem/2218/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n; cin >> n;
    while(n--){
        ll a; cin >> a;
        for(ll j = 1; j <= 2*a; j+=2){
            cout << 1LL * j * (j+2) << " ";
        }

        cout << "\n";
    }

    return 0;
}