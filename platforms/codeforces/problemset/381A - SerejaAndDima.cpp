// https://codeforces.com/problemset/problem/381/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int l = 0, r = n-1;

    int a = 0, b = 0;
    int turn = 0;
    while(l <= r){
        if(nums[l] > nums[r]){
            if(turn == 0) a+= nums[l];
            else b+= nums[l];
            l++;
        }else{
            if(turn == 0) a+= nums[r];
            else b+= nums[r];
            r--;
        }
        turn = (turn == 0 ? 1 : 0);
    }

    cout << a << " " << b << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

