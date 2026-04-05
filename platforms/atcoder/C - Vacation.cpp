// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+4;
vector<vector<int>> dp(maxN, vector<int>(3, 0));
vector<int> a(maxN, 0);
vector<int> b(maxN, 0);
vector<int> c(maxN, 0);

void solve(int n){
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 0; i < n; i++){
        dp[i+1][0] = max(dp[i][1], dp[i][2]) + a[i]; // Best choice if i chose A
        dp[i+1][1] = max(dp[i][0], dp[i][2]) + b[i]; // Best choice if i chose B
        dp[i+1][2] = max(dp[i][0], dp[i][1]) + c[i]; // Best choice if i chose C
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    solve(n);
}