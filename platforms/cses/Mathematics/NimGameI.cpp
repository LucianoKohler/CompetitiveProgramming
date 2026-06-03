#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ans ^= a;
    }

    // f*cking theorem
    cout << (ans > 0 ? "first\n" : "second\n");
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
