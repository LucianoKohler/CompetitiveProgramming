// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main(){
  map<int, int>hashmap;

  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    int val;
    cin >> val;
    if(hashmap[k-val]){
        cout << (hashmap[k-val]) << " " << i+1 << endl;
        return 0;
    }
    hashmap[val] = i + 1;
  }
  cout << "IMPOSSIBLE" << endl;
}