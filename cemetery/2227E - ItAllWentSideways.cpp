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
      vector<int>nums(n, 0);
      for(int i = 0; i < n; i++){
        cin >> nums[i];
      }

      if(n == 1) {
        cout << 0 << "\n";
        continue;
      }

      int i;
      for(i = n-1; i >= 0; i--){
        if(nums[i] <= nums[i-1]){
          break;
        }
      }

      if(i != 0) nums[i]--;
      ll wallHeight = nums[n-1];
      ll qtd = 0;

      // n-1 no one will move since they are at the wall
      for(int i = n-2; i >= 0; i--){
        if(nums[i] >= wallHeight){
          // cout << "na coluna " << i << "cairam " << nums[i]-wallHeight << " bolas\n";
          qtd += nums[i]-wallHeight;
          wallHeight = wallHeight;
        }else{
          // cout << "na coluna " << i << "cairam 0 bolas\n";
          wallHeight = nums[i];
        }
      }

      cout << qtd << "\n";
    }
    return 0;
}

/*
o
oo
oo    
oo    
ooo   x
oooooxo
ooooooo
ooooooo

     oxooo
ooooxooooo
oooooooooo

o  
ooo    ooox
ooooooxoooo

Ideias
X - ponto menor global
X - ponto imediatamente menor
-  

     o
    oo
   ooo
  oooo
 ooooo
oooooo

o
oo
*/