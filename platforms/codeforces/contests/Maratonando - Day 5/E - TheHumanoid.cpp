// https://codeforces.com/group/4QT6JKdRZ8/contest/526955/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int> nums;

ll test(ll h, ll serum1, ll serum2, ll serum3){
    stack<ll>s;
    s.push(serum1);
    s.push(serum2);
    s.push(serum3);

    ll i;
    for(i = 0; i < nums.size(); i++){
        while(h <= nums[i] && !s.empty()){
            h *= s.top(); s.pop();
        }

        if(h > nums[i]){
            h += nums[i]/2;
        }else{
            break;
        }
    }
    return i;
}

void solve(){
    ll n, h; cin >> n >> h;
    ll qtdOne = 0;
    for(int i = 0; i < n; i++) {
        ll num; cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    
    ll best = 0;
    best = max(best, test(h, 2, 2, 3));
    best = max(best, test(h, 2, 3, 2));
    best = max(best, test(h, 3, 2, 2));
    
    nums.clear();
    cout << best << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}