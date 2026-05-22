// https://codeforces.com/group/4QT6JKdRZ8/contest/520029/problem/G  
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    // 505
    string s = to_string(n);
    int qtdDigits = 0;
    for(char c : s){
        if(c == '0') continue;
        qtdDigits++;
    }
    cout << qtdDigits << "\n";

    string zeroes = "";
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '0'){
            zeroes += "0";
            continue;
        }
        
        cout << s[i] + zeroes << " ";
        zeroes += "0";
    }

    cout << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
