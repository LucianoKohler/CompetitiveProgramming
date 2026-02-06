#include <bits/stdc++.h>
using namespace std;

// Code above not needed

class Solution {
public:
int maxSubArray(vector<int>& nums){ // Kadane's Algorithm
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
}};