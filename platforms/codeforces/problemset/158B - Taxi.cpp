// https://codeforces.com/problemset/problem/158/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int qtdTaxis = 0;
    int l = 0, r = n-1;
    while (l <= r){
        int cap = 4;
        cap-=nums[r];
        while(nums[l] <= cap){
            cap-=nums[l]; 
            l++;
        }
        r--;
        qtdTaxis++;
    }

    cout << qtdTaxis << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

