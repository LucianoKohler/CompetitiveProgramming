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
      vector<int>nums(n, 0);

      for(int i = 0; i < n; i++) cin >> nums[i];
      int ans;
      if(nums[0] == 1){
        ans = 2;
      }else{
        ans = 1;
      }

      for(int i = 1; i < n; i++){
        if(ans+1 == nums[i]){
          ans+= 2;
        }else{
          ans++;
        }
      }

      cout << ans << "\n";
    }
    return 0;
}
