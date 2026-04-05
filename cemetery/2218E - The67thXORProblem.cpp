#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        vector<ll> nums(a, 0);

        for(int i = 0; i < a; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
    
        while(nums.size() > 1){
            for(int k = 0; k < nums.size(); k++){
                nums[k] ^= nums.back();
            }
            nums.pop_back();
            sort(nums.begin(), nums.end());
        }

        cout << nums.back() << "\n";

    }
    return 0;
}