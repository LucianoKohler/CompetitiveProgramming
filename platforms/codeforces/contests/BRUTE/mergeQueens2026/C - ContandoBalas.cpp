// https://codeforces.com/group/4QT6JKdRZ8/contest/688925/attachments
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;

    vector<int> g(n, 0);
    vector<int> a(n, 0);
    
    for(int i = 0; i < n; i++) cin >> g[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> cloneg = g;
    sort(cloneg.begin(), cloneg.end()); // 1 2 3 4
    vector<int> clonea = a;
    sort(clonea.begin(), clonea.end(), greater<>()); // 4 3 2 1    
    
    for(int i = 1; i < n; i++){
      if(cloneg[i]+clonea[i] != cloneg[i-1]+clonea[i-1]){
        cout << "NAO\n";
        return 0;
      }
    }

    cout << "SIM\n";
    int idealVal = cloneg[0] + clonea[0];

    for(int i = 0; i < n; i++){
      if(i != 0) cout << " ";
      cout << idealVal - a[i];
    }

    return 0;
}
