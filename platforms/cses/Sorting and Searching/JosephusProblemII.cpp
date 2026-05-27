// https://cses.fi/problemset/task/2162/       
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    set<int>nums; // sets remove in log(n) and have the next() method, so perfect for this problem

    for(int i = 1; i <= n; i++) nums.insert(i);
    
    // Start with kth child
    auto it = nums.begin();
    for(int i = 0; i < k; i++){
        it = next(it);
    }
    int printedNum;

    while(nums.size() > 0){
        cout << *it << " ";
        printedNum = *it;
        
        // Advance k times in set
        for(int i = 0; i <= k; i++){
            it = next(it);
            if(i == 0) nums.erase(printedNum);
            if(nums.size() == 0) break;
            if(it == nums.end()) it = nums.begin();
        }
    }
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}