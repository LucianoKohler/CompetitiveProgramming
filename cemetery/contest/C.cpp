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

void solve(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    vector<int> freq(mx, 0);
    int qtdProblems = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        freq[nums[i]]++;
        if(freq[nums[i]] == 2) qtdProblems++;
    }

    int qtdMoves = 0;
    int i = 0;
    while(qtdProblems > 0){
        qtdMoves++;
        freq[nums[i]]--;
        if(freq[nums[i]] == 1) qtdProblems--;
        i++;
    }

    cout << qtdMoves << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}