// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int num = 0;
    size_t n; cin >> n;
    
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        if((2*a-b)%3 == 0 && (2*a-b) >= 0 && (2*b-a)%3 == 0 && (2*a-b) >= 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
} 
