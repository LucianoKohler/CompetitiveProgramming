// https://codeforces.com/problemset/problem/2229/C1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int qtdFlipped = 0;
    vector<int>flips;
    for(int i = n-1; i >= 0; i--){
        if((nums[i] > 0 && qtdFlipped % 2 == 0) || (nums[i] < 0 && qtdFlipped % 2 == 1)){
            qtdFlipped++;
            flips.push_back(i+1);
        }
    }

    cout << flips.size() << "\n";
    for(int flip : flips) cout << flip << " ";
    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}