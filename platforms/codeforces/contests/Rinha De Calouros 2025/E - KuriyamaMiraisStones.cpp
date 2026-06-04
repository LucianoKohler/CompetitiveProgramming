// https://codeforces.com/group/4QT6JKdRZ8/contest/612670/problem/E     
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<ll>sorted = nums;

    sort(sorted.begin(), sorted.end());

    vector<ll>pref(n, 0);
    vector<ll>prefSorted(n, 0);

    pref[0] = nums[0];
    prefSorted[0] = sorted[0];

    for(int i = 1; i < n; i++){
        pref[i]       = pref[i-1]       + nums[i];
        prefSorted[i] = prefSorted[i-1] + sorted[i];
    }

    // for(int i = 0; i < n; i++) cout << pref[i] << " ";
    // cout << "\n";
    // for(int i = 0; i < n; i++) cout << prefSorted[i] << " ";

    int q; cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        b--; c--;
        if(a == 1){
            if(b == 0){
                cout << pref[c] << "\n";
            }else{
                cout << pref[c] - pref[b-1] << "\n";
            }
        }else{
            if(b == 0){
                cout << prefSorted[c] << "\n";
            }else{
                cout << prefSorted[c] - prefSorted[b-1] << "\n";
            }
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}

/*
6 4 2 7 2 7
2 2 4 6 7 7
    3     6
    4 + 6 + 7 + 7 = 24

*/