// https://codeforces.com/group/4QT6JKdRZ8/contest/603077/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<int>needed(n, 0);
    vector<int>bought(n, 0);

    for(int i = 0; i < n; i++) cin >> needed[i];
    for(int i = 0; i < n; i++) cin >> bought[i];
    
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
      mini = min(mini, bought[i]/needed[i]);
    } 
    cout << mini << "\n";
    return 0;
}