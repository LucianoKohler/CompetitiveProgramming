#include <bits/stdc++.h>

using namespace std;


int solve(vector<int>& nums){ // Algoritmo de Kadane
    int size = nums.size();
    int best = 0, sum = 0;
    for (int i = 0; i < size; i++) {
    sum = max(nums[i],sum+nums[i]);
    best = max(best,sum);
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