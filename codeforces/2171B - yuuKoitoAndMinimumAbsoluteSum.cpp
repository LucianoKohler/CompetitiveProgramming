// https://codeforces.com/contest/2171/problem/B
#include <bits/stdc++.h>
 
// Expression: | an - a1 |
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        int a[m];

        for(int i = 0; i < m; i++) cin >> a[i];
        
        if(a[0]   == -1) a[0] = a[m-1];
        if(a[m-1] == -1) a[m-1] = a[0];
        
        for(int i = 0; i < m; i++) if(a[i] == -1) a[i] = 0;
        
        cout << abs(a[m-1] - a[0]) << endl;
        for(int i = 0; i < m; i++) cout << a[i] << " ";
        cout << endl;
    }
}