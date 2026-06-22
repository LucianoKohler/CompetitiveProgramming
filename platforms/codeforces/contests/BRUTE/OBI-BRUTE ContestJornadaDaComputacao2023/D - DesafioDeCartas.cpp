// https://codeforces.com/group/4QT6JKdRZ8/contest/473126/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    bool isCrescent = true;
    bool isDecrescent = true;
    int num; cin >> num;
    for(int i = 1; i < 5; i++){
        int a; cin >> a;

        if(a >= num) isDecrescent = false;
        if(a <= num) isCrescent = false;
        num = a;
    }

    if(isCrescent)        cout << "C\n";
    else if(isDecrescent) cout << "D\n";
    else                  cout << "N\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}