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

ll fat(ll n){
    if(n <= 1) return 1;
    return n * fat(n-1);
}

int main(){

    cin.tie(0) -> sync_with_stdio(0);
    string str; cin >> str;
    vector<char>s;

    for(char c : str){
        s.push_back(c);
    }

    sort(s.begin(), s.end());

    // First step: Calculate total ways
    // Which is just permutation with repetition formula

    ll totalWays = fat(s.size()); 

    char comparedChar = '#'; // Sentinel value
    int qtdRepeated = 0;

    // Finding repetitions
    for(char c : s){
        if(c != comparedChar){
            totalWays /= fat(qtdRepeated);
            qtdRepeated = 1;
            comparedChar = c;
        }else{
            qtdRepeated++;
        }
    }
    
    totalWays/= fat(qtdRepeated);
    cout << totalWays << "\n";

    // Showing each permutation
    do{
        for(char c : s){
            cout << c;
        }

        cout << "\n";
    }while(next_permutation(s.begin(), s.end()));
    
    return 0;
}