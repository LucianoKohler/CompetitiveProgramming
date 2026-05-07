// https://codeforces.com/problemset/status/2217/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9 + 7;
const int mx = 2e5 + 5; // This varies!
vector<int> nums(mx, 0);

int maxChangesFrom(int l, int r){
  int qtd = 0;
  int lastVal = nums[l];
  for(int i = l; i <= r; i++){
    if(nums[i] != lastVal){
      lastVal = nums[i];
      qtd++;
    }
  }

  return qtd;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> nums[i];
    int s; cin >> s; s--;

    int ans = max(maxChangesFrom(0, s), maxChangesFrom(s, n-1));
    if(ans % 2 == 1) ans++;
    cout << ans << "\n";
  }
  return 0;
}
