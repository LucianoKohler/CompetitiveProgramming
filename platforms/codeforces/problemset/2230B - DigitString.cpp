// https://codeforces.com/problemset/problem/2230/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    string s; cin >> s;
    
    int ans = 0;
    int odds = 0;
    int minRemotions = 0;
    for(char c : s){
        if(c == '4'){
            ans++;
        }else if(c == '1' or c == '3'){
            odds++;
        }else{
            // Best scenario is removing this 2 + other remotions, or just the odds
            minRemotions = min(minRemotions + 1, odds); 
        }
    }

    cout << ans + minRemotions << "\n";
}

// Chill man that's a B

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
