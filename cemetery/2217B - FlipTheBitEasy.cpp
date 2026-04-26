// https://codeforces.com/problemset/status/2217/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9 + 7;
const int mx = 2e5 + 5; // This varies!

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int s; cin >> s; s--;
    int x = nums[s];
    int qtdMoves = 0;
    
    cout << qtdMoves << "\n";
  }
  return 0;
}
/*
0 1 0 1 0 1
3
    
0 1 0 1 0 1
-----------
0 1 1 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 0
    
        V
0 1 1 0 1 1 0 1 0 0 1 0 1 0 1 0 1

0 1 1 1 1 1 0 1 0 0 1 0 1 0 1 0 1

*/


