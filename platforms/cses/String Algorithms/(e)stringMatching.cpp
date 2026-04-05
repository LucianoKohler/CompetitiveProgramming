// https://cses.fi/problemset/task/1753
// TLE

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string str; cin >> str;
    string subs; cin >> subs;
    int occur = 0;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == subs[0]){
            
            bool isOccur = true;
            for(int j = i; j < i+subs.length(); j++){
                if(str[j] != subs[j-i]) isOccur = false;
            }
            
            if(isOccur) occur++;
        }
    }
    
    cout << occur << endl;

}