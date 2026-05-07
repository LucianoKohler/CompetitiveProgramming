// https://codeforces.com/group/4QT6JKdRZ8/contest/632878/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<int>red(n, 0);
    vector<int>blue(n, 0);

    for(int i = 0; i < n; i++) cin >> red[i];
    for(int i = 0; i < n; i++) cin >> blue[i];

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end(), greater<>());

    int least = INT_MAX, most = 0;
    int difference;
    for(int i = 0; i < n; i++){
      difference = red[i] + blue[i];
      least = min(least, difference);
      most = max(most, difference);
    }

    cout << most - least << "\n";
    return 0;
}
