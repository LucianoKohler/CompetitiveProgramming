// https://cses.fi/problemset/task/1141/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;


void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    map<int, int>present;

    for(int i = 0; i < n; i++) cin >> nums[i];

    if(n == 1){
      cout << "1\n";
      return;
    }

    int l = 0, r = 0;
    present[nums[l]]++;
    int maxVal = 0, curr = 1;
    while(r < n){
      r++;
      curr++;

      if(r == n){
        break;
      }

      if(present[nums[r]]){ // Already present
        while(present[nums[r]]){
          present[nums[l]]--;
          l++;
          curr--;
        }
      }

      present[nums[r]]++;
      maxVal = max(maxVal, curr);
    }

    cout << maxVal << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}