#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    double n; cin >> n;
    
    int count = 0;
    for(ll i = 5; i <= n; i*=5){
        count+= (n/i);
    }
    
    cout << count << endl;
    
}