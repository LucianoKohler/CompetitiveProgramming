// https://codeforces.com/group/4QT6JKdRZ8/contest/520029/problem/F     
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n; cin >> n;
    vector<ll>nums(n, 0);
    ll maxV = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        maxV = max(maxV, nums[i]);
    }

    if(n == 1) {
        cout << nums[0] << "\n";
        return;
    }

    if(n == 2){
        cout << max(nums[0], nums[1]) << "\n";
        return;
    }
    // Binary search: Say "can we read all questions in mid time?" If so, decrease, if not, increase
    ll low = maxV, high = 1e15; 
    while(low < high){
        ll mid = (low+high)/2;

        // cout << low << " " << mid <<  " " << high << "\n";
        
        ll sum = 0;
        ll qtdPeopleNeeded = 1;
        for(int i = 0; i < n; i++){
            if(sum+nums[i] <= mid) sum+=nums[i];
            else {
                qtdPeopleNeeded++;
                sum = 0;
                i--;
            }
        }

        if(qtdPeopleNeeded <= 3){ // We can read all questions with 3 people
            high = mid;
        }else{
            low = mid+1;
        }
    }

    cout << low << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}
