// https://cses.fi/problemset/task/1722
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
ll T[2][2] = {{1, 1},{1, 0}};
ll E[2][2] = {{1, 1}, {1, 0}};

void multiply(ll A[2][2], ll B[2][2]){
    ll a = (((A[0][0] * B[0][0]) % modulo) + ((A[0][1] * B[0][1]) % modulo)) % modulo;
    ll b = (((A[0][0] * B[1][0]) % modulo) + ((A[0][1] * B[1][1]) % modulo)) % modulo;
    ll c = (((A[1][0] * B[0][0]) % modulo) + ((A[1][1] * B[0][1]) % modulo)) % modulo;
    ll d = (((A[1][0] * B[1][0]) % modulo) + ((A[1][1] * B[1][1]) % modulo)) % modulo;

    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;

    return;
}

ll fib(ll n){

    // Calculate T^n with binary exponentiation approach
    while(n){
        if(n%2 == 1){
            multiply(T, E);
        }
        multiply(E, E);
        
        n>>=1;
    }

    // cout << T[0][0] << " " << T[0][1] << "\n";
    // cout << T[1][0] << " " << T[1][1] << "\n";

    return T[1][1];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n; cin >> n;

    cout << fib(n) << "\n";

    return 0;
}