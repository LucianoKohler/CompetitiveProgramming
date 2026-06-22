// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/N
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
map<int, int>rows;
map<int, int>cols;

void solve(){
    int row, col, q; cin >> row >> col >> q;

    while(q--){
        int a;
        cin >> a;

        if(a == 1){ // Build
            int b, c; cin >> b >> c;
            rows[b] = 1;
            cols[c] = 1;
        }else{ // Query
            int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
            if((rows[xa] || cols[ya]) && (rows[xb] || cols[yb])){
                cout << "SIM\n";
            }else{
                cout << "NAO\n";
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
