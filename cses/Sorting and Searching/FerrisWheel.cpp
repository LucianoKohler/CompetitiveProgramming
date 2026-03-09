#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int solve(vector<ll>children, ll maxW, ll n){
    int qtd = 0;
    int weightLeft = 0;
    int l = 0;
    int r = n-1;
    while(l <= r){
        qtd++;
        weightLeft = maxW;

        weightLeft -= children[r];
        r--;
        
        if(children[l] <= weightLeft){
            l++;
        }

    }

    cout << qtd;
    return qtd;
}

int main(){
    ll n; cin >> n;
    ll maxW; cin >> maxW;
    vector<ll>children;
    for(ll i = 0; i < n; i++){
        ll child;
        cin >> child;
        children.push_back(child); 
    }

    sort(children.begin(), children.end());

    solve(children, maxW, n);
    return 0;
}