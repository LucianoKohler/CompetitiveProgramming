// https://codeforces.com/group/4QT6JKdRZ8/contest/603077/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a<b) swap(a, b);
    if(c<d) swap(c, d);
    if(a == c && b+d == a){
      cout << "SIM\n";
    }else{
      cout << "NAO\n";
    }
    return 0;
}
