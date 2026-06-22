// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
      set<char>s;
      int n; cin >> n;
      string str; cin >> str;
      int sum = 0;

      for(auto c : str){
        if(s.count(c)){
          sum++;
        }else{
          s.insert(c);
          sum+=2;
        }
      }

      cout << sum << "\n";
  
    }
    return 0;
}
