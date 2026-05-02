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
    string ans;
    switch(n){
      case 1:
      ans = "walk";
        break;
      case 2:
      ans = "no";
        break;
      case 3:
      ans = "no";
        break;
      case 4:
      ans = "no";
        break;
      case 5:
      ans = "yes";
        break;
      case 6:
      ans = "yes";
        break;
      case 7:
      ans = "backwards";
        break;
      case 8:
      ans = "seven";
        break;
    }

    cout << ans;
    return 0;
}
