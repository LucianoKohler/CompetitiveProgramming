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
const int mx = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    vector<int>nums(n, 0);
    unordered_map<int, int>map;
    for(auto &it : nums) cin >> it;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int target = k - (nums[i] + nums[j]);
            if(target  <= 0) continue;
            if(map.count(target)){
                auto it = map.find(target);
                if(it != map.end()){
                    cout << i+1 << " " << j+1 << " " << (*it).second+1 << "\n";
                    return;
                }
            }else{
                map[nums[i]] = i;
                map[nums[j]] = j;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}