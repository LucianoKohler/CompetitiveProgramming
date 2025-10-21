// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

// Código acima dispensável ao colar na Leetcode
class Solution {
    unordered_map<int, int> hashmap;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vals(2);
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (hashmap.count(target - num)) {
                auto it = hashmap.find(target - num);
                if (it != hashmap.end()) {
                    vals[0] = i;
                    vals[1] = it->second;
                }
            }
            hashmap[num] = i;
        }
        return vals;
    }
};