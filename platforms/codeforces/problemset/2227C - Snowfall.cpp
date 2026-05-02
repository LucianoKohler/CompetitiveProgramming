/*
    .                           .....   
    .--.    B L O C K I E R    -----...
    ...--.                . .-=---.....
     ...----==###==#####==###==-. .....
      -===###=-=#=-=####=-----##==.. .. 
      -=-   .-#======##==-.--=-   .-. .
     .==  .    .###=###=-=-=- .    -.. 
    .==-       .--===##====--      ..-.
  ..==#-.     ==--====###===--=.  ..--..
 ..-====##===##===============--====-...
 ..-=========######======--- ...==-----.
  .-==========#####==....        =---...
....====-===#=######.           .=---. 
. .-====--=#########=--.        ----=-. 
...-###=========--------.     ===--..-.
..######=#===---....            ==--...
-=########===-.                      .
-=##########==--.                       
===#####=======--..             
*/        
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
      vector<pair<int, int>>nums;

      vector<int>reorder;

      for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back({num, 0}); // {num, not used}
      }

      for(int i = 0; i < n; i++){
        if(nums[i].second == 0 && nums[i].first % 6 == 0){
          reorder.push_back(nums[i].first);
          nums[i].second = 1;
        }
      }

      for(int i = 0; i < n; i++){
        if(nums[i].second == 0 && nums[i].first % 2 == 0){
          reorder.push_back(nums[i].first);
          nums[i].second = 1;
        }
      }

      for(int i = 0; i < n; i++){
        if(nums[i].second == 0 && nums[i].first % 3 != 0){
          reorder.push_back(nums[i].first);
          nums[i].second = 1;
        }
      }
      
      for(int i = 0; i < n; i++){
        if(nums[i].second == 0){
          reorder.push_back(nums[i].first);
          nums[i].second = 1;
        }
      }
      for(int i = 0; i < n; i++){
        cout << reorder[i] << " ";
      }

      cout << "\n";
    }
    return 0;
}

/*
%6 NEEDS to be in one of the borders
%3 only is divisible by 6 if multiplied by %2 and vice versa

i 12 7 9 4 18 5
a 12 18 4 7 5 9
m 12 18 4 7 9 5

i 1 10 15 20 3 6 9
a 6 10 20 1 15 3 9
m 6 10 20 1 15 3 9


*/