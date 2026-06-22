// https://codeforces.com/group/4QT6JKdRZ8/contest/518512/problem/D 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, hp; cin >> n >> hp;
    vector<ll>stabs(n, 0);
    vector<ll>maxEffect(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> stabs[i];
        if(i > 0) maxEffect[i-1] = stabs[i] - stabs[i-1];
    }

    maxEffect[n-1] = 1e18;


    // cout << "Max effect of a stab: \n";
    // for(int i = 0; i < n; i++) {
    //     cout << maxEffect[i] << "\n";
    // }

    // Binary search: Can we kill with k = ???
    ll l = 0, r = 1e18;
    while(l < r){
        ll mid = (l+r)/2;

        // Can we kill using mid poison power?
        ll damageDone = 0;
        for(ll i = 0; i < n; i++){
            damageDone += min(maxEffect[i], mid);
        }

        if(damageDone >= hp){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    cout << l << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}