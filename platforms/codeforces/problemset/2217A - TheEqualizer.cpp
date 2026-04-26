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
    while(n--){

        int m, k; cin >> m >> k;
        int sum = 0;
        for(int i = 0; i < m; i++){
            int num; cin >> num;
            sum += num;
        } 

        /*
        if the special move makes an even number, he will win
        (he passes after using special move)
        if the sum of the numbers is odd, he will win
        */

        if((m*k)%2 == 0 || sum % 2 == 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        } 
    }
    return 0;
}
