#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 100;
const int mv = 1000;
/* 3 coins:  4 8 1
1° for: only using { 4 }
1 0
2 0
3 0
4 1
5 0
6 0
7 0
8 0
9 0
10 0
11 0
12 0
13 0

2° for: only using { 4, 8 }
1 0
2 0
3 0
4 1
5 0
6 0
7 0
8 1
9 0
10 0
11 0 
12 1
13 0

3° for: only using { 4, 8, 1 }
1 1
2 0
3 0
4 1
5 1 // keep a "coinUsed, if used, set to true, you can't make the sum, and if not, you can use it"
6 0
7 0
8 1
9 1
10 0
11 0
12 0
13 1

1, 4, 5, 8, 9, 13
*/

int dp[mx*mv];
bool coinUsed[mx*mv];
ll maxSum;

void resetV(){
    for(int i = 0; i <= maxSum; i++) coinUsed[i] = false;
}

void solve(){
    int qtdCoins; cin >> qtdCoins;
    vector<int>coins(qtdCoins, 0);
    for(int i = 0; i < qtdCoins; i++){
        cin >> coins[i];
        maxSum += coins[i];
    }

    dp[0] = 1;
    int qtdPossibleSums = 0;

    for(int coin : coins){
        for(int j = 0; j <= maxSum; j++){
            if(j+coin <= maxSum){
                if(!coinUsed[j] && dp[j] > 0 && dp[j+coin] == 0){ // If i can make the sum and it has not been done before
                    if(dp[j] == 1){ // I managed to get to this sum before
                        dp[j+coin] = 1;
                        coinUsed[j+coin] = 1;
                        qtdPossibleSums++;
                    }
                }
            }
        }
        resetV();
    }

    cout << qtdPossibleSums << "\n";
    for(int i = 1; i <= maxSum; i++){
        if(dp[i] == 1){
            cout << i << " ";
        }
    }

    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
