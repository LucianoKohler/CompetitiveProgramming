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
    vector<pair<int, int>>c;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        c.push_back({a, b});
    }

    sort(c.begin(), c.end());

    int l = c[0].first, r = c[0].first;
    int i = 0;
    int qtd = 0;
    while(i < n){
        /* 0
           r
        _###_____
        __#######
        ____####_
        Steps:
        1. Move r to end of current customer
        2. For i until last concurrent customer, count and move l to start of last customer
        3. i becomes last customer index
        4. Repeat
        */
        r = c[i].second;
        cout << "Analisando o tempo " << r << "\n";
        int currQtd = 0;
        for(int j = i; j < n; j++){
            if(r > c[j].first && c[j].second){ // "dead" customer
                i++;
                continue;
            }
            if(r >= c[j].first && r <= c[j].second){ // Is concurrent
                cout << "Cliente " << j << " esta presente\n";
                currQtd++;
                qtd = max(qtd, currQtd);
                i++;
            }else{
                cout << "Cliente " << j << " nao ta mais\n";
                break;
            }
        }
    }
    cout << qtd << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}


/*
i = 3
7
1 8
2 3
4 8
6 11
7 11
11 15
11 11
       r              
########_______
_##____________ 
___#####_______
_____######____
______#####____ <-
__________#####
__________#____
*/