// https://cses.fi/problemset/task/1158

/*
4 10
4 8 5 3
5 12 8 1

4 books, 10 dollars
(p, v)
(4, 5)
(8, 12)
(5, 8)
(3, 1)

dp:
d\b 1  2  3  4 
0  00 00 00 00
1  00 00 00 00
2  00 00 00 00
3  00 00 00 01               max(leave it      or       take it           )
4  05 05 05 05 <- dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + value[i])
6  05 05 08 08
7  05 05 08 08
8  05 12 12 12
9  05 12 12 12
10 05 12 13 13 


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxDollars 1e5+7
#define maxBooks 1004

vector<vector<int>> dp(maxBooks, vector<int>(maxDollars, 0));
vector<int> prices(maxBooks, 0);
vector<int> pages(maxBooks, 0);

void solve(int n, int budget){
    for(int i = 0; i <= budget; i++){ // For each budget
        // If possible, get first book (best when we have only 1 book)
        dp[i][0] = i >= prices[0] ? pages[0] : 0; 

        for(int j = 1; j < n; j++){ // For each book
            if(i-prices[j] >= 0){
                dp[i][j] = max(dp[i][j-1], dp[i-prices[j]][j-1] + pages[j]);
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[budget][n-1] << endl;
}

int main(){
    int n, budget; cin >> n >> budget;
    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    solve(n, budget);
  return 0;
}
