#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n; cin >> n;
    
    ll qtd = 0;
    // Every 5 in the fat gives a 0 at the end
    // Every 25 gives two 0s at the end (5*5)
    // Every 125 gives three 0s at the end (5*5*5)
    // ...
    // This only happens if there are enough even numbers
    // to multiply 2*5, but they are more abundant than 5s in the sequence
    for(ll i = 5; i <= n; i*=5){
        qtd+= (n/i);
    }
    
    cout << qtd << endl;
    
}