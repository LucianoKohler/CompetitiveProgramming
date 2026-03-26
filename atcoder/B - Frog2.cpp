// https://atcoder.jp/contests/dp/tasks/dp_a
// Transition: op(n) = min(op(n-1) + |h[n-1] - h[n]|, op(n-2) + |h[n-2] - h[n], ... K times)
// Base case: op(0) = 0, op(1) = |h[0] - h[1]|, op(2) = |h[0] - h[2]

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+4;
vector<int> h(maxN);
vector<int> dp(maxN);

void solve(int n, int k){
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int best = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                best = min(best, (dp[i-j] + abs(h[i-j] - h[i])));
            }
        }

        dp[i] = best;
    }
    cout << dp[n-1] << endl;
}

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];

    solve(n, k);
}