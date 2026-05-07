// https://codeforces.com/group/4QT6JKdRZ8/contest/688925/attachments
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int a, b; cin >> a >> b;
    if(a%2 == 1 && b%2 == 1){
      cout << -1 << "\n";
    }else if(a%2 == 0 && b%2 == 0){
      cout << max(a, b) << "\n"; 
    }else if(a%2 == 0){
      cout << a << "\n";
    }else{
      cout << b << "\n";
    }

    return 0;
}
