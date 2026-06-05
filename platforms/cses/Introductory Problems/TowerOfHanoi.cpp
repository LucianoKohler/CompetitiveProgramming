// https://cses.fi/problemset/task/2165
#include<bits/stdc++.h>
using namespace std;

/*
Using recursion we can,for a problem with n blocks

- move n-1 blocks to the auxiliary pile
- move the leftover block to the target pile
- move the n-1 blocks back to the target pile

base case: n = 1, where we just move the block to our target
*/

void hanoi(int n, int curr, int targ, int aux){
    if(n == 1) {
        cout << curr << " " << targ << "\n";
        return;
    }

    hanoi(n-1, curr, aux, targ);
    cout << curr << " " << targ << "\n";
    hanoi(n-1, aux, targ, curr);
}

void solve(){
    int n; cin >> n;
    cout << pow(2, n) -1 << "\n"; // Moves to solve hanoi with n blocks
    hanoi(n, 1, 3, 2);
    // Craaazy
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}