#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int intervalTier = 0;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<int>figs(n, 0);
    for(int i = 0; i < n; i++) cin >> figs[i];
    
    // Finding max T
    int mT = 0;
    vector<int>clone = figs;
    sort(clone.begin(), clone.end());
    for(int i = 0; i < n; i++){
      if(clone[i] == mT+1){
        mT++;
      }
    }

    if(mT == 0){
      cout << "-1" << endl;
      return 0;
    }


    // Solving
    vector<int> qtdFigs(mT+1, 0);
    int l = 0, r = 0;
    int minInterval = 1e9;

    if(figs[r] <= mT){
      qtdFigs[figs[r]]++; // Adds first card
      intervalTier++;
    }

    // Start by adding until we got a suitable set (1...n)
    while(intervalTier < mT){
      r++;
      if(figs[r] > mT) continue; // If it's trash, collect and go

      if(qtdFigs[figs[r]] == 0){ // If is new on the interval
        intervalTier++;
      }
      qtdFigs[figs[r]]++; // Add it
    }

    minInterval = r-l+1; // Preliminary result

    // Main loop
    while(r < n){

      // Keep removing from the left until we get a problem
      while(intervalTier == mT){
        if(figs[l] > mT) { // trash, just remove
          minInterval = min(minInterval, (r-l+1)-1);
          l++;
          continue;
        }

        qtdFigs[figs[l]]--;
        if(qtdFigs[figs[l]] == 0){
          intervalTier--;
        }else{ // It's safe to remove
          minInterval = min(minInterval, (r-l+1)-1);
        }
        l++;
      }

      // Keep adding to the right until fix the problem
      while(intervalTier != mT){
        r++;
        if(r >= n) break;
        if(figs[r] > mT) continue;
        if(qtdFigs[figs[r]] == 0){
          intervalTier++;
        }
        qtdFigs[figs[r]]++;
      }

      if(intervalTier == mT){
        minInterval = min(minInterval, r-l+1);
      } // If not, we incremented to an invalid subsequence

      // If we reach here and there are still more to the right,
      // the parent while will run again, on a cycle of removing
      // from the left, adding to the right
    }

    cout << minInterval <<"\n";
    return 0;
}
