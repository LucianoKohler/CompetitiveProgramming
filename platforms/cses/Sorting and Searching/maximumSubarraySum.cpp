#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int>& nums){ // Kadane's Algorithm
    int maxVal = -INT_MAX; // For all negative vectors
    int size = nums.size();
    int best = 0, sum = 0;
    for (int i = 0; i < size; i++) {
        maxVal = max(maxVal, nums[i]);
        sum = max(nums[i],sum+nums[i]);
        best = max(best,sum);
    }
    
    if(best == 0){
        best = maxVal;
    }

    return best;
}

signed main(){
    int n;
    vector<int> nums;
    int num;
    
    cin >> n;
    
    while(n--){
        cin >> num;
        nums.push_back(num);
    }

    cout << solve(nums) << "\n";
}