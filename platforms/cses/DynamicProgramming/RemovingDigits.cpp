// https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

int highDigit(string n){
  int maxN = 0;
  for(char c : n){
    maxN = max(maxN, c-'0');
  }
  return maxN;
}

void solve(){
    string n; cin >> n;
    int steps = 0;

    while(stoi(n) > 0){
      steps++;
      n = to_string(stoi(n) - highDigit(n));
    }

    cout << steps << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
