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
const ll modulo = 998244353;
const int mx = 2e5+4;
vector<int>dp(mx, 0);

/*
Remember he cycles of 1 XOR 2 XOR ... XOR n
1   2   3  4
------------
1   3   0  4
------------
1, n+1, 0, n

ones = floor(n/4) + (n%4 >= 1)
zeroes = floor(n/4) + (n%4 >= 3)
only 2 of the for cases matters for us (1 xor 1 and 0 xor 0)
remember to count the rest of the vector!!
*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
      ll n, x; cin >> n >> x;
      ll qtdOnes = floor(n/4) + (n%4 >= 1);
      ll qtdZeroes = floor(n/4) + (n%4 >= 3);

      // We need to contain x
    }
    return 0;
}

/*
0 1 2 3 4 5 6 7 8
0 1 3 0 4 1 7 0 8

*/