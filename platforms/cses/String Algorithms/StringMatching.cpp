// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string str; cin >> str;
    string subs; cin >> subs;
    int n = str.size();
    int l=0, r=1;
    int matchSize = 0;
    int qtdMatches = 0;

    if(subs.size() > str.size()){
        cout << "0\n";
        return 0;
    }

    if(str[l] == subs[0]){
        matchSize++;
        if(matchSize == subs.size()){
            qtdMatches++;
            l = 1;
        }else if(subs.size() > 1 && str[r] == subs[1]){ // k = 1
            matchSize++;
        }
    } // Wtf is this problem

    while(r<n){
        while(true){
            r++;
            if(r==n) break;
            if(matchSize == subs.size()) break;

            if(str[r] == subs[matchSize]) matchSize++;
            else break;
        }

        if(matchSize == subs.size()){
            qtdMatches++;
            r -= matchSize-1;
            if(str[r] == subs[0])  matchSize = 1;
            else matchSize = 0;
        }else{
            matchSize = 0;
        }
    }

    cout << qtdMatches << "\n";
}