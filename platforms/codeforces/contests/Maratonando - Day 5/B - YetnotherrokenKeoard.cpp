// https://codeforces.com/group/4QT6JKdRZ8/contest/526955/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    string s; cin >> s;
    deque<pair<char, int>>uppercases;
    deque<pair<char, int>>lowercases;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'b'){
            if(lowercases.size() > 0) lowercases.pop_back(); 
            continue;
        }
        if(s[i] == 'B'){
            if(uppercases.size() > 0) uppercases.pop_back(); 
            continue;
        }    
        if(s[i] >= 'a' && s[i] <= 'z'){ lowercases.push_back({s[i], i}); continue;}
        if(s[i] >= 'A' && s[i] <= 'Z'){ uppercases.push_back({s[i], i}); continue;}
    }

    string ans;
    while(!lowercases.empty() || !uppercases.empty()){
        if(uppercases.empty()){
            ans += lowercases.front().first;
            lowercases.pop_front();
            continue;
        }

        if(lowercases.empty()){
            ans += uppercases.front().first;
            uppercases.pop_front();
            continue;
        }

        if(lowercases.front().second < uppercases.front().second){
            ans += lowercases.front().first;
            lowercases.pop_front();
        }else{
            ans += uppercases.front().first;
            uppercases.pop_front();
        }
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}