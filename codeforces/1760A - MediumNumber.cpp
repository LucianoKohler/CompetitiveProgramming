#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    
    while(n--){
        int a, b, c; cin >> a >> b >> c;
        cout << a+b+c - min(a, min(b, c)) - max(a, max(b, c)) << endl;
    }
    return 0;
}