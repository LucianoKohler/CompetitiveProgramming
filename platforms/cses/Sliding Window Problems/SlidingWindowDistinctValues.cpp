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

map<int, int>qtd;

void solve(){
    int n, k; cin >> n >> k;
    vector<int>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int l = 0, r = k-1;
    int qtdDistinct = 0;
    for(int i = l; i <= r; i++){
        if(!qtd[nums[i]]) qtdDistinct++; // If i didn't have one
        qtd[nums[i]]++;
    }

    cout << qtdDistinct;

    while(r < n-1){

        qtd[nums[l]]--;
        if(!qtd[nums[l]]) qtdDistinct--;
        l++;//     Pew                    °o.    
        r++;//            pew                      .o° 
        if(!qtd[nums[r]]) qtdDistinct++;
        qtd[nums[r]]++;

        cout << " " << qtdDistinct;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
