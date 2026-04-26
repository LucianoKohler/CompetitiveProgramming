#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    while(n--){
        ll x, y; cin >> y >> x;
        ll xAns, yAns;

        if(y%2==0) yAns = y*y;
        else       yAns = (y-1)*(y-1)+1;
        if(x%2==1) xAns = x*x;
        else       xAns = (x-1)*(x-1)+1;
        
        if(y > x){
            if(y%2==0)cout << yAns-(x-1);
            else cout << yAns+(x-1);
            
        }else if(x > y){
            if(x%2==1)cout << xAns-(y-1);
            else cout << xAns+(y-1);
        }else{
            cout << (xAns+yAns)/2;
        }

        cout << "\n";
    }
    return 0;
}