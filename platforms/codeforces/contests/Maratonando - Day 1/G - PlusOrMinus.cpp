// https://codeforces.com/group/4QT6JKdRZ8/contest/513876/problem/G    
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      int a, b, c; cin >> a >> b >> c;
      cout << (a+b == c ? "+" : "-") << "\n"; 
    }
    return 0;
}
