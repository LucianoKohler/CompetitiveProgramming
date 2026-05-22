// https://codeforces.com/group/4QT6JKdRZ8/contest/520029/problem/E 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>>pairs(26, {0, 0}); // {A, a}, {B, b}

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c-'a' < 0){ // uppercase
            pairs[c-'A'].first++;
        }else{
            pairs[c-'a'].second++;
        }
    }
    
    // for(int i = 0; i < 26; i++) cout << pairs[i].first << " ";
    // cout << "\n";
    // for(int i = 0; i < 26; i++) cout << pairs[i].second << " ";
    
    for(int i = 0; i < 26; i++){
        if(k == 0) break;
        // 2 4
        if(pairs[i].first > pairs[i].second) swap(pairs[i].first, pairs[i].second);
        
        if(pairs[i].second-2 >= pairs[i].first){
            k--;
            pairs[i].first++;
            pairs[i].second--;
            i--;
        }
    }
    
    int maxPairs = 0;
    for(int i = 0; i < 26; i++) maxPairs += min(pairs[i].first, pairs[i].second);
    cout << maxPairs << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
