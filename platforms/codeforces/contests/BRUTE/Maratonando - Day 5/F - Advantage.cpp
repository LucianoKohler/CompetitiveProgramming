// https://codeforces.com/group/4QT6JKdRZ8/contest/526955/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    int maxV = 0;
    int sMaxV = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(nums[i] >= maxV){
            sMaxV = maxV;
            maxV = nums[i];
        }else if(nums[i] > sMaxV){
            sMaxV = nums[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] == maxV){
            cout << nums[i] - sMaxV << " ";
        }else{
            cout << nums[i] - maxV << " ";
        }
    }

    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}