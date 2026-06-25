// https://codeforces.com/gym/106601/problem/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;

    for(int i = 1; i <= 100; i++){
        if((n*i) % 100 == 0){
            cout << i << "\n";
            return;
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}