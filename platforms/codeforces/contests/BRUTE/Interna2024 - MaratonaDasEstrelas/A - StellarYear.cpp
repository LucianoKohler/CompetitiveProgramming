// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n, x; cin >> n >> x;
    vector<int>nums(n, 0);
    int qtd = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(x % nums[i] == 0 || x == 0) qtd++;
    }

    cout << qtd << "\n";

    if(x == 0){
        for(int i = 0; i < n; i++) cout << i+1 << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(x % nums[i] == 0) cout << i+1 << " ";
    }

    cout << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
