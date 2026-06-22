// https://codeforces.com/group/4QT6JKdRZ8/contest/513876/problem/E  
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
      int minimum = INT_MAX;
      int sum = 0;
      for(int i = 0; i < n; i++){
        int num; cin >> num;
        minimum = min(minimum, num);
        sum += num;
      }

      cout << sum - (minimum*n) << "\n";
    }
    return 0;
}


/*
1 1 1 10 -> 9
1 2 3 4 4 -> 9



*/