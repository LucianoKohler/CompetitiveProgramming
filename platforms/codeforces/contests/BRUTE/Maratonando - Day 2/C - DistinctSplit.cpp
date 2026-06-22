// https://codeforces.com/group/4QT6JKdRZ8/contest/516987/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int>freq(26, 0);
    vector<int>revFreq(26, 0);
    vector<int>uniques(n, 0);
    vector<int>revUniques(n, 0);

    if(n == 2){
      cout << "2\n";  
      return;
    }

    for(int i = 0; i < n; i++){
      if(i != 0) uniques[i] = uniques[i-1];
      if(freq[s[i]-'a'] == 0) uniques[i]++;
      freq[s[i]-'a']++;
    }

    for(int i = n-1; i >= 0; i--){
      if(i != n-1) revUniques[i] = revUniques[i+1];
      if(revFreq[s[i]-'a'] == 0) revUniques[i]++;
      revFreq[s[i]-'a']++;
    }

    // cout << "\n";
    // for(int i = 0; i < n; i++) cout << uniques[i] << " ";
    // cout << "\n";
    // for(int i = 0; i < n; i++) cout << revUniques[i] << " ";
    // cout << "\n";

    int maxi = 0;
    for(int i = 0; i < n-1; i++){
      maxi = max(maxi, uniques[i] + revUniques[i+1]);
    }

    cout << maxi << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
