// https://cses.fi/problemset/task/1717/        
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1e6+5; // This varies!

ll fat[mx];
ll invFat[mx];

ll binExp(ll a, ll b){
    ll ans = 1;
    
    while(b){
        if(b & 1) ans = (ans * a) % modulo; 
        a = (a*a) % modulo;
        b >>= 1;
    }

    return ans;
}

void preCalcFactorial(ll n){
    fat[0] = 1;
    fat[1] = 1;
    
    // Calculate fats
    ll ans = 1;
    for(int i = 2; i <= n; i++){
        ans = (ans * i) % modulo;
        fat[i] = ans;
    }

    // Calculate invFats (note that i/i! = invFat[i-1])
    invFat[n] = binExp(fat[n], modulo-2);
    for(int i = n; i > 0; i--){
        invFat[i-1] = (i * invFat[i]) % modulo;
    }
}

ll binCoef(ll n, ll k){ // nCk (n choose k)
    ll ans = (fat[n] * invFat[k]) % modulo;
    ans = (ans * invFat[n-k]) % modulo;
    return ans;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    // Pre-calculate all factorials and inverses
    preCalcFactorial(mx); 

    int n; cin >> n;
    ll badCases = 0;

    for(int i = 1; i <= n; i++){
        ll aux = (binCoef(n, i) * fat[n-i]) % modulo;
        if(i%2==1){
            badCases = (badCases + aux) % modulo;
        }else{
            badCases = (badCases - aux) % modulo;
        }
    }

    cout << (fat[n] - badCases) % modulo << endl;
    return 0;
}
