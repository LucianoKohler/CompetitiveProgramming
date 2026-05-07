// https://codeforces.com/group/4QT6JKdRZ8/contest/513876/problem/F    
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;

    while(t--){
      int n, k, maxT; cin >> n >> k >> maxT;
      vector<int>intervals;
      vector<int>temps(n, 0);
      for(int i = 0; i < n; i++) cin >> temps[i];

      int l=0, r=0; // Go right, find interval, move L to R, repeat
      while(r<n){
        if(temps[r] <= maxT){
          while(true){ // Go until bad temperature
            r++;
            if(r == n){
              if(r-l >= k){ // Possible interval, add
                intervals.push_back(r-l);
              }
              break;
            }else{
              if(temps[r] > maxT){ // End of interval
                if(r-l >= k){ // Possible interval, add
                  intervals.push_back(r-l);
                }
                break;
              }
            }
          }
        }
        l = r;
        while(l < n && temps[l] > maxT){
          l++; r++;
        }
      }

      // We got intervals now
      ll sum = 0;
      if(intervals.size() == 0){
        cout << "0\n";
      }else{
        for(int num : intervals){ // 5 days, k = 3, we can get 3, 4 or 5 days
          for(int i = k; i <= num; i++){
            sum += num-i+1;
          }
        }
        cout << sum << "\n";
      }

    }

    return 0;
}
