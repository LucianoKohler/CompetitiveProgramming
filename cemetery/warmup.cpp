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
const int mx = 51; // This varies!


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int capacities[k+1];

        vector<int>bags[n+1];

        for(int i = 0; i < k; i++) cin >> capacities[i];
        capacities[k] = 1000;

        for(int i = 0; i < n; i++){
            int course; cin >> course;
            bags[course].push_back(i);
        }

        int actions = 0;
        // While we can do actions and our we still have courses to move
        while(bags[n+1].size() != n){
            for(int i = k; i >= 0; i--){
                
            }
        }
    }
    return 0;
}

/*
n, k (courses and priorities)
capacities
wish of every course

4 2
2 2
3 3 3 3

5 3
1 2 3
1 2 4 2 3

1 2 3 L
1 2 5 4    
  4

*/