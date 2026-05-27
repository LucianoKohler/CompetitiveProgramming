// https://cses.fi/problemset/task/2162/       
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    set<int>nums; // sets remove in log(n) and have the next() method, so perfect for this problem

    for(int i = 1; i <= n; i++) nums.insert(i);
    
    // Start with 2
    auto it = next(nums.begin());
    int printedNum;

    while(nums.size() > 0){
        cout << *it << " ";
        printedNum = *it;
        
        // Advance twice in set
        it = next(it);
        if(it == nums.end()){
            it = nums.begin();
        }

        // We can erase since the pointer is not there anymore
        nums.erase(printedNum);
        if(nums.size() == 0) break;
        
        it = next(it);
        if(it == nums.end()){
            it = nums.begin();
        }
        
        nums.erase(printedNum);

    }
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}