// https://cses.fi/problemset/task/1158
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mWeight = 1e5 + 3;
const int mItems = 1000 + 3;
vector<int> dp(mWeight, 0);

void solve(){
    int n, mW; cin >> n >> mW;
    vector<int>value(n+1, 0);
    vector<int>weight(mW+1, 0);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> value[i];

    // For each book
    for(int i = 0; i < n; i++){
        // For each weight (decreasing so we don't get the same book more than once)
        for(int w = mW; w >= 0; w--){
            // Leave it or take it
            if(w-weight[i] >= 0){
                dp[w] = max(dp[w], dp[w-weight[i]] + value[i]);
            }
        }
    }

    cout << dp[mW] << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}