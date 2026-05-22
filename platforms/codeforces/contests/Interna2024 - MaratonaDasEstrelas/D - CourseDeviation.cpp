// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    reverse(nums.begin(), nums.end());
    
    int height = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] >= height){
            height = nums[i];
        }
        height++;
    }

    cout << height+1 << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
   solve();

    return 0;
}