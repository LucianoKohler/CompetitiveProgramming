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
    string s; cin >> s;
    char minLetter = 'z';
    int minLetterI = -1;

    if(n == 1){
        cout << s << "\n";
        return;
    }

    for(int i = 1; i < n; i++){
        if(s[i] <= minLetter){
            minLetter = s[i];
            minLetterI = i;
        }
    }

    for(int i = 0; i < minLetterI; i++){
        if(s[i] > s[minLetterI]){ 
            swap(s[i], s[minLetterI]);
            break;
        }
    }

    cout << s << "\n";

}

int main(){
    solve();

    return 0;
}