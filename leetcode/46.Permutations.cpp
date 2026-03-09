#include<bits/stdc++.h>
using namespace std;

// Do not copy above lines

class Solution {
public:
    vector<vector<int>> res; // Global answer
    vector<vector<int>> permute(vector<int>& nums) { // Not used since the header does not include a vector<int>&permutation
        vector<int> permutation;
        permuteAux(nums, permutation);
        return res;
    }

    void permuteAux(vector<int>& nums, vector<int>& permutation){
        if(permutation.size() == nums.size()){ // Base case: The permutation is complete
            res.push_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            bool found = false;
            for(int x : permutation){
                if(x == nums[i]){
                    found = true;
                }
            }
            if(!found){ // If the number is not in nums, create a new permutation with the unused number and recursively call permuteAux(), 
                vector<int> newPermutation = permutation;
                newPermutation.push_back(nums[i]);
                permuteAux(nums, newPermutation);
            }
        }
    }
};