// https://codeforces.com/problemset/problem/2220/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        vector<int> nums(m, 0);
        for(int i = 0; i < m; i++) cin >> nums[i];
        sort(nums.begin(), nums.end(), greater<int>());

        // Check if impossible
        bool impossible = false;
        for(int i = 1; i < m; i++){
            if(nums[i] == nums[i-1]){
                impossible = true;
                break;
            }
        }

        if(impossible){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < m; i++){
            if(i == 0) { cout << nums[i]; continue;}
            cout << " " << nums[i];
        }
        cout << "\n";
    }
    return 0;
}