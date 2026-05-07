#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(ll k){
    // if(k == 1){
    //     cout << "0\n";
    //     return;
    // }else if(k == 2){
    //     cout << "6\n";
    //     return;
    // }else if(k == 3){
    //     cout << "28\n";
    //     return;
    // }

    // The above cases are not needed because MAGICALLY the factors below 
    // cancel eachother out (craaazyy)
    
    // Total - invalid
    ll totalWays = ((k*k) * ((k*k)-1))/2;
    // For the invalid ways I opened an empty 8x8 grid and noted the pattern 
    ll wrongWays = 0;
    wrongWays += 2*4; // Borders
    wrongWays += 3*8; // (0,1), (1, 0), ...
    wrongWays += 4*(k-3) * 4;
    wrongWays += 6*(k-4)*4;
    wrongWays += 8*(k-4)*(k-4);
    wrongWays /=2;

    cout << totalWays - wrongWays << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll k; cin >> k;
    for(ll i = 1; i <= k; i++) solve(i);

    return 0;
}