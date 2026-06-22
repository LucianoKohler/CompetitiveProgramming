// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;

    while(t--){
      int num; cin >> num;
      string s; cin >> s;

      if(num <= 1){
        cout << num << "\n";
        continue;
      }
      int l = 0, r = num-1;
      while(l < r && s[l] != s[r]){
        l++; r--;
      }

      cout << (r-(l-1)) << "\n";
    }
    return 0;
}
