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

        vector<int>bags[k+1];

        for(int i = 0; i < k; i++) cin >> capacities[i];
        capacities[k] = 1000;

        for(int i = 0; i < n; i++){
            int course; cin >> course;
            bags[course-1].push_back(i);
        }

        int actions = 0;
        for(int i = 0; i <= k; i++) actions += bags[i].size()*(k-i);
        cout << actions << "\n";
        // While we can do actions and our we still have courses to move
        while(bags[k].size() != n){

            for(int i = k-1; i >= 0; i--){
                if(bags[i].empty()) continue;

                if(bags[i+1].size()+1 <= capacities[i+1]){
                    bags[i+1].push_back(bags[i][0]);
                    cout << bags[i][0]+1 << " ";
                    bags[i].erase(bags[i].begin());
                }else{
                    continue;
                }
            }
        }

        cout << "\n";
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