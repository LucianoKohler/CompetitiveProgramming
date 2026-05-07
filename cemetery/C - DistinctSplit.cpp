// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

ll distincts(string str){
  set<char>s;
  for(char c : str){
    s.insert(c);
  }

  return s.size();
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      int n; cin >> n;
      string s; cin >> s;
      int l = 0, r = n-1;
      int max = 0;

      while(l <= r){
        int mid = (l+r)/2;
      }


    }
    return 0;
}
