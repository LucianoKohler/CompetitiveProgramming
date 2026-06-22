// https://codeforces.com/group/4QT6JKdRZ8/contest/632878/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
      int num; 
      cin >> num;
      if(num >= m){
        cout << i << "\n";
        return 0;
      }
    }
    
    cout << "-1\n";
    return 0;
  }