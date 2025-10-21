// https://cses.fi/problemset/1646/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int n, q;
    cin >> n >> q;
    ll nums[n];
    ll sum[n];

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(i==0){
          sum[i] = nums[i];
        }else{
          sum[i] = sum[i-1] + nums[i];
        }
    }
    
    while(q--){
        int a, b;
        cin >> a >> b;
        if (a == 1){
          cout << sum[b-1] << endl;
        }else{
          cout << sum[b-1] - sum[a-2] << endl;
        }
    }
 
    return 0;
}