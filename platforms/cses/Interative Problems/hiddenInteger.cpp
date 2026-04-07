#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1e9 // This varies!

int main(){
    ll l = 0;
    ll r = mx;
    for(int i = 0; i < 30; i++){
        ll mid = (l+r)/2;
        cout << "? " << mid << "\n";
        string ans; cin >> ans;
        if(ans == "YES"){ // Num is smaller
            l = mid;
        }else{ // Num is greater or equal than
            r = mid;
        }
    }

    cout << "! " << l+1;

    return 0;
}
