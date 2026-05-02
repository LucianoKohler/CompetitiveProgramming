#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 1e5+5; // This varies!
vector<int>nums(2*mx, 0);
int num = 123;

// If palindrome uses 2 zeroes
vector<bool>contains(mx+1, 0);

// If palindrome has 0 in the middle
vector<bool>containsL(mx+1, 0);
vector<bool>containsR(mx+1, 0);

int n;

void resetContains(){
  for(int i = 0; i <=n; i++){
    contains[i] = 0; 
    containsL[i] = 0; 
    containsR[i] = 0; 
  }
}

bool palindromeCheck(int l, int r){
  contains[nums[(l+r)/2]] = 1;
  while(l < r){
    contains[nums[l]] = 1;
    if(nums[l] != nums[r]) return false;
    l++; r--;
  }
  return true;
}

void middleCheck(int mid, int leftOrRight){
  if(!leftOrRight) containsL[nums[mid]] = 1;
  else containsR[nums[mid]] = 1;

  int l = mid-1, r = mid+1;
  if(l < 0) return;
  if (r == 2*n) return;

  while(nums[l] == nums[r]){
    if(!leftOrRight) containsL[nums[l]] = 1;
    else containsR[nums[l]] = 1;
    l--;
    r++;
    if(l < 0) break;
    if (r == 2*n) break;
  }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      cin >> n;
      resetContains();

      for(int i = 0; i < 2*n; i++){
        cin >> nums[i];
      }

      auto itFirstZero =  find(nums.begin(), nums.end(), 0);
      auto itSecondZero = find(itFirstZero+1, nums.end(), 0);
      int l = itFirstZero-nums.begin(); 
      int r = itSecondZero-nums.begin();
      

      if(!palindromeCheck(l, r)){ // We have 0 in the middle of a palindrome (or it is just 0)
        middleCheck(l, 0); 
        middleCheck(r, 1); 
        int i;
        int biggest = -1;

        for(i = 0; i <= n; i++){
          if(containsL[i] == 0){
            biggest = 1; // R is bigger
            break;
          }

          if(containsR[i] == 0){
            biggest = 0; // L is bigger
            break;
          }
        }

          if(biggest == 0){
            for(int j = i; j <= n; j++){
              if(!containsL[j]){
                cout << j << "\n";
                break;
              }
            }
          }else{
            for(int j = i; j <= n; j++){
              if(!containsR[j]){
                cout << j << "\n";
                break;
              }
            }
          }
        

      }else{ // We have a palindrome between 0 and 0
        while(nums[l] == nums[r]){
          contains[nums[l]] = 1;
          l--; r++;
          if(l < 0) break;
          if(r == 2*n) break;
        }

        for(int i = 0; i <= n; i++){
          if(contains[i] == 0){ 
            cout << i << "\n";
            break;
          }
        }
      }
    }
    return 0;
}
