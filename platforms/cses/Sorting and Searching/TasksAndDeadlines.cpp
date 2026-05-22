#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>>tasks;

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        tasks.push_back({a, b}); // Sort by time
    }

    sort(tasks.begin(), tasks.end());

    ll sum = 0;
    ll time = 0;
    for(int i = 0; i < n; i++){
        time += tasks[i].first;
        sum += tasks[i].second - time;
    }

    cout << sum << "\n";
    return 0;
}

/*
5 12
6 10
8 15

11

4 + 1

*/