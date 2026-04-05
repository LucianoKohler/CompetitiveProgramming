// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<ll>sticks;

    for(int i = 0; i < n; i++){
        ll stick; cin >> stick;
        sticks.push_back(stick);
    }
    
    sort(sticks.begin(), sticks.end()); // To get the right median

    int targ = sticks[n/2]; // Median
    ll cost = 0;

    for(int i = 0; i < n; i++){
        ll difference = sticks[i] - targ;
        cost += llabs(difference); // Absolute value
    }

    cout << cost << endl;
} 
