// https://atcoder.jp/contests/dp/tasks/dp_a
// Transition: op(n) = min(op(n-1) + |h[n-1] - h[n]|, op(n-2) + |h[n-2] - h[n])
// Base case: op(0) = 0, op(1) = |h[0] - h[1]|, op(2) = |h[0] - h[2]

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+4;
vector<int> h(maxN);
vector<int> dp(maxN);

void solve(int n){
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    dp[2] = abs(h[0] - h[2]);

    for(int i = 3; i <= n; i++){
        dp[i] = min(
            (dp[i-1] + abs(h[i-1] - h[i])),
            (dp[i-2] + abs(h[i-2] - h[i]))
        );
    }
    cout << dp[n-1] << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];

    solve(n);
}