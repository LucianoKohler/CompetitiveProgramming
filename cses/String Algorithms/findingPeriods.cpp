// https://cses.fi/problemset/task/1733

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string str; cin >> str;
    string period = "";
    
    period += str[0];
    int iPeriod = 0;
    
    int j = 1;
    for(int i = 1; i < str.length(); i++){
        if(str[i] == period[0]){
            if(period == str.substr(i, period.length())){
                iPeriod = i;
                break;
            }
        }else{
            period[j] = str[i];
            j++;
        }
    }

    if(iPeriod != 0){   
        for(int i = iPeriod; i < str.length(); i+=iPeriod){
            cout << i << " ";
        }
    }
    
    cout << str.length() << endl;

}