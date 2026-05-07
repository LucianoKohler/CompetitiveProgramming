// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){

      char c; cin >> c;
      string s = "codeforces";
      bool is = false;
      for(int i = 0; i < s.length(); i++){
        if(c == s[i]) is = true;
      }

      if(is){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }
    return 0;
}
