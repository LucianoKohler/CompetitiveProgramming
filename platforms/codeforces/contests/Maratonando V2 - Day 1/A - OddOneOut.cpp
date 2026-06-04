// https://codeforces.com/group/4QT6JKdRZ8/contest/602583/problem/A 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a != b && a !=c){
        cout << a << "\n";
    }else if(b!= a && b!= c){
        cout << b << "\n";
    }else{
        cout << c << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}