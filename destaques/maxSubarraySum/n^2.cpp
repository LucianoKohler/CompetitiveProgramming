#include <bits/stdc++.h>

using namespace std;


int solve(vector<int>& nums){
    int size = nums.size();
    int best = 0, sum = 0;
    
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            sum+=nums[j];
            best = max(best, sum);
        }
        sum = 0;
    }

    return best;
}

int main(){
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