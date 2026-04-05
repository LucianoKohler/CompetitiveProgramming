#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // Bitmask method!!
        int n = nums.size();
        vector<vector<int>>subs;

        for(int i = 0; i < 1 << n; i++){
            vector<int> v;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){ // Bit in position j is on
                    v.push_back(nums[j]);
                }
            }
            subs.push_back(v);
        }

        return subs;
    }
};
