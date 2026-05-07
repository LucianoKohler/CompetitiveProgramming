// https://codeforces.com/group/4QT6JKdRZ8/contest/513876/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      int a, b, c, d; cin >> a >> b >> c >> d;
      int place = 0;
      if(a < b) place++;
      if(a < c) place++;
      if(a < d) place++;

      cout << place << "\n";
    }
    return 0;
}
