#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<ll> nums(n, 0);
    
    // Number generator (testcase is made with parameters)
    ll x, a, b, c; cin >> x >> a >> b >> c;
    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = ((a*nums[i-1])+b)%c;
    }

    ll sum = 0;
    for(int i = 0; i < k; i++) sum += nums[i];
    ll sumXorred = sum;
    
    ll l = 0, r = k-1;
    while(r < nums.size()-1){
        sum -= nums[l];
        l++;
        r++;
        sum += nums[r];
        sumXorred ^= sum;
    }
    
    cout << sumXorred << "\n";

    return 0;
}
