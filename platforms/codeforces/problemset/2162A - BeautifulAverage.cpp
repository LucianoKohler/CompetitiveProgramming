// https://codeforces.com/contest/2162/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        int max = 0;
        for(int i = 0; i < m; i++){
            int o;
            cin >> o;
            if(o > max){
                max = o;
            }
        }
        
        cout << max << endl;
    }
    
    return 0;
}