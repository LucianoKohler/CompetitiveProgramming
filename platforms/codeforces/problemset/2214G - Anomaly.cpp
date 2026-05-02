// https://codeforces.com/problemset/problem/2214/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    string s = "bigchadjeff";
    while(t--){
        int n; cin >> n;
        cout << s[n-1] << "\n";
    }
    return 0;
}
