// https://codeforces.com/group/4QT6JKdRZ8/contest/520029/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    if(n == 2){
        cout << nums[0]*nums[1] << "\n";
        return;
    }

    ll maxPositive = 0, secMaxPositive = 0;
    ll maxNegative = 0, secMaxNegative = 0;
    for(ll num : nums){
        if(num > 0){
            if(num > maxPositive){
                secMaxPositive = maxPositive;
                maxPositive = num; 
            }else if(num > secMaxPositive){
                secMaxPositive = num;
            }
        }else{
            if(num < maxNegative){
                secMaxNegative = maxNegative;
                maxNegative = num; 
            }else if(num < secMaxNegative){
                secMaxNegative = num;
            }
        }
    }

    if(maxPositive * secMaxPositive > maxNegative * secMaxNegative){
        cout << maxPositive*secMaxPositive << "\n";
    }else{
        cout << maxNegative*secMaxNegative << "\n";
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
