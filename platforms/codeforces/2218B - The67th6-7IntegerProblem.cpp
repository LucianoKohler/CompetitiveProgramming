#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;

    for(int j = 0; j < n; j++){
    
        vector<int> nums(7, 0);
        for(int i = 0; i < 7; i++) cin >> nums[i];
    
        sort(nums.begin(), nums.end());
    
        int sum = 0;
        for(int i = 0; i < 6; i++){
            sum += -nums[i];
        }
    
        sum+= nums[6];
    
        cout << sum << "\n";

    }
    return 0;
}