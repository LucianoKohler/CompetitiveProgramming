#include <bits/stdc++.h>
using namespace std;

// Ignore above lines when copying

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if(nums[0] == "0") return "1";
        
        int stringSize = nums[0].length();

        vector<int> numbers; // Transform into int vector
        for(int i = 0; i < nums.size(); i++){
            numbers.push_back(stoi(nums[i], nullptr, 2)); 
            // String to convert, pointer to first non int index and base
        }
        
        // Sort
        sort(numbers.begin(), numbers.end());

        // Find first non appearing element
        for(int i = 0; i < stringSize*stringSize; i++){
            
            if(i >= numbers.size() || numbers[i] != i){
                bitset<16>ans(i);
                return ans.to_string().substr(16-stringSize);
            }
        }
        return "0";
    }
};