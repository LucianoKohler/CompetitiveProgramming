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
    vector<int>full(5);
    vector<int>missing(5);
    for(int i = 0; i < 5; i++) cin >> full[i];
    for(int i = 0; i < 4; i++) cin >> missing[i];
    missing[4] = 10000;

    sort(full.begin(), full.end());
    sort(missing.begin(), missing.end());

    for(int i = 0; i < 5; i++){
      if(full[i] != missing[i]){
        cout << full[i] << "\n";
        return 0;
      }
    }
    return 0;
}