// https://codeforces.com/group/4QT6JKdRZ8/contest/612670/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    int days = 0;
    int cycle = a[0] + a[1] + a[2];
    days += (n/cycle)*3;
    n %= cycle;

    int i = 0;
    while(n > 0){
        n -= a[i];
        days++;
        i++;
    }

    cout << days << "\n";


}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}