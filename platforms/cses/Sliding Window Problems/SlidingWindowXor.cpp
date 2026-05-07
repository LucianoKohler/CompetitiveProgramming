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
#define int long long
const int modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> nums(n, 0);
    nums[0] = x;

    for(int i = 1; i < n; i++) nums[i] = ((a*nums[i-1])+b)%c;    
    int l = 0, r = k-1;
    int totalXor = 0;
    int currXor = 0;
    for(int i = l; i < k; i++){ // Don't xor the last element
        currXor ^= nums[i];
    }

    // It will be xorred on the while
    totalXor ^= currXor;
    while(r < n-1){
        currXor ^= nums[l];
        l++;
        r++;
        currXor ^= nums[r];
        totalXor ^= currXor;
    }

    cout << totalXor << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
