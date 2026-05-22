// https://cses.fi/problemset/task/3399
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
    int n, b, a; cin >> n >> a >> b;
    int c = n - (a+b);
    int qtdDraws = c;
    int qtdWins = b;
    int qtdLosses = a;

    vector<int>A;
    vector<int>B;
    for(int i = 1; i <= n; i++){
        A.push_back(i);
    }

    int state = 0; // Draw, lose, win
    int aux = n;
    int aux2 = qtdDraws+1;
    if(qtdDraws == 0) state = 1;

    for(int i = 0; i < n; i++){
        if(state == 0){
            B.push_back(i+1);
            c--;
            if(c == 0) state++;
        }else if(state == 1){
            B.push_back(aux);
            aux--;
            a--;
            if(a == 0) state = 2;
        }else{
            B.push_back(aux2);
            aux2++;
            b--;
            if(b == 0)break;
        }
    }

    // Check if is valid
    int simDraws = 0, simWins = 0, simLosses = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == B[i]){
            simDraws++;
        }else if(A[i] < B[i]){
            simLosses++;
        }else{
            simWins++;
        }
    }

    if(simWins == qtdWins && simDraws == qtdDraws && simLosses == qtdLosses){
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << B[i] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++) cout << A[i] << " ";
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

/*
---
1 2 3 4 -> 2 wins
1 2 3 4 -> 1 win

draws -> losses -> wins
1 2 3 4
1 4 2 3
---



 



 

*/