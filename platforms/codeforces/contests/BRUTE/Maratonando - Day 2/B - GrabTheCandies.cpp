// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/C
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
      int evenSum = 0;
      int oddSum = 0;
      
      for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(num%2==0){
          evenSum+=num;
        }else{
          oddSum+=num;
        }
      }

      if(evenSum > oddSum){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }

    }
    return 0;
}
