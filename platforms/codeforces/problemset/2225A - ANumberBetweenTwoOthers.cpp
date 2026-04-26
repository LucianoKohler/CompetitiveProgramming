// https://codeforces.com/problemset/problem/2225/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;

/*
Since x and y are multiples, we can get a number divisible by x and not by y
just by subtracting y from x, if there is more than 1 multiple in the range,
we can return YES, if not, then the y-x will be x, we can return NO then.
*/

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        if(y-x > x){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}