// https://codeforces.com/group/4QT6JKdRZ8/contest/526955/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    map<int, int> mats;

    int maxN = 0;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        mats[num]++;
        maxN = max(maxN, mats[num]);
    }


    cout << maxN << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}