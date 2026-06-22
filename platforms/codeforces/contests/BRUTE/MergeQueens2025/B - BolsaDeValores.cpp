// https://codeforces.com/group/4QT6JKdRZ8/contest/603077/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

/*
11
1 2 3 2 1

1
2
3
2
1
1 2
2 3
3 2
2 1
1 2 3
3 2 1

LOGIC
find intervals of AP via sliding window
every consecutive pair is a progression, so we ignore 
those of length 1 and 2 and sum them on the end

After that, sum possibilities

Above example: 
arithmetic progression on [0, 2] (length 3) and on [2, 4] (length 3)
*/

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    if(n == 1){
      cout << "1\n";
      return 0;
    }

    if(n == 2){
      cout << "3\n";
      return 0;
    }
    vector<int>intervals;

    int r = 0;
    int cd = nums[1]-nums[0];
    while(r<n){
      
      int currentProgSize = 1;
      while(true){
        r++;
        if(r == n) break;

        if(nums[r] == nums[r-1]+cd){
          currentProgSize++;
        }else{
          break;
        }
      }

      if(currentProgSize >= 3) intervals.push_back(currentProgSize);
      
      if(r < n){ // Still there's more to go, find the cd and continue
        cd = nums[r] - nums[r-1];
        r--; // Get the first element of the progression that we missed
      }
    }

    ll sum = 0;
    sum += n; // Intervals of size 1
    sum += n-1; // Intervals of size 2
    if(intervals.size() > 0){
      for(int num : intervals){
        for(int i = 3; i <= num; i++){
          sum+= num-(i-1);
        }
      }
    }

    cout << sum << "\n";

    return 0;
}
