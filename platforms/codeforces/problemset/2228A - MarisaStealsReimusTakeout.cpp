// https://codeforces.com/problemset/problem/2228/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

// Counts: [0], [1, 2], [1, 1, 1], [2, 2, 2]
void solve(){
    int n; cin >> n;
    int ops = 0;
    int zeroes=0, ones=0, twos=0;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(num == 0) zeroes++;
        if(num == 1) ones++;
        if(num == 2) twos++;
    }

    ops += min(ones, twos); // [0, 1]
    ones -= ops; twos -= ops;

    ops += zeroes; // [0]
    ops += ones/3; // [1, 1, 1]
    ops += twos/3; // [2, 2, 2]

    cout << ops << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
