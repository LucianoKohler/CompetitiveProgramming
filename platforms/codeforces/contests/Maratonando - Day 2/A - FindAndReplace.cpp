// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      int n; cin >> n;
      string s; cin >> s;
      map<char, char>m;
      m[s[0]] = '1';

      bool can = true;
      for(int i = 1; i < n; i++){
        if(m[s[i]]){ // Substituted

        }else{ // Substitute
          if(m[s[i-1]] == '1'){
            m[s[i]] = '2';
          }else{
            m[s[i]] = '1';
          }
        }

        if(m[s[i]] == m[s[i-1]]){
          can = false;
          break;
        }
      }

      if(can){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
      
    }
    return 0;
}
