
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2e5+4

vector<ll> nums(mx);

void solve(int n){
    stack<pair<ll, int>> s; // value, index
    s.emplace(0, 0);
    
    for(int i = 0; i < n; i++){ // For each number
        if(nums[i] <= s.top().first){
            while(nums[i] <= s.top().first){ // Remove elements until finding a smaller value
                s.pop();
            }
        }

        cout << s.top().second << " ";
        s.emplace(nums[i], i+1);
    }

    cout << endl;
}

int main(){
    int n; cin >> n; // 1-Indexed
    for(int i = 0; i < n; i++) cin >> nums[i];

    solve(n);
}