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
    int n; cin >> n;
    vector<int>figs(n, 0);
    for(int i = 0; i < n; i++) cin >> figs[i];
    
    // Achando T maximo
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


    return 0;
}
