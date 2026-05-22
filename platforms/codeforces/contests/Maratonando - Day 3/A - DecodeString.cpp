// https://codeforces.com/group/4QT6JKdRZ8/contest/518512/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int>v;
    for(char c : s){
        v.push_back(c-'0'); // char to int
    }

    int p = 0;
    while(p < s.size()){
        if(p+2 < s.size()){ // 1 100
            if(v[p+2] == 0){
                if(p+3 < s.size() && v[p+3] == 0){ // Its a J
                    cout << (char)(v[p]+96);
                    p++;
                }else{
                    cout << (char)(v[p+0]*10 + v[p+1] + 96);
                    p+=3;
                }
            }else{
                cout << (char)(v[p]+96);
                p++;
            }
        }else{
            cout << (char)(v[p]+96);
            p++;
        }
    }
    cout << "\n";
    // a = 97

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}