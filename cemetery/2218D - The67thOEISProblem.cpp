#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n; cin >> n;
    while(n--){
        ll a; cin >> a;
        for(ll j = 1; j <= a; j++){
            cout << 1LL * j * (j+1) << " ";
        }

        cout << "\n";
    }

    return 0;
}