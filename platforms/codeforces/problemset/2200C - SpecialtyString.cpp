// https://codeforces.com/contest/2200/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    stack<char> st;
    string s; cin >> s;

    st.emplace(s[0]);

    for(int i = 1; i < n; i++){
        if(st.empty() || st.top() != s[i]){
            st.emplace(s[i]);
        }else{
            st.pop();
        }
    }

    cout << (st.size() == 0 ? "YES\n" : "NO\n");
    return;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}