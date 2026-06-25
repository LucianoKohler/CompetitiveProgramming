// https://cses.fi/problemset/task/1619/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

/*
Think of the arrival and leaving of customers 
as events, if we declare something like this:

{3, 1}, {5, -1}

we can say that a customer arrived at time 3 and one left at time 5, 
with this, we can easily find the biggest occupation at a given time
*/

void solve(){
    int n; cin >> n;
    vector<pair<int, int>>events;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        events.push_back({a, 1}); // Someone entered
        int b; cin >> b;
        events.push_back({b, -1}); // Someone left
    }

    sort(events.begin(), events.end());

    int maxCustomers = 0;
    int currCustomers = 0;
    for(auto [time, event] : events){
        if(event == 1) currCustomers++;
        if(event == -1) currCustomers--;

        maxCustomers = max(maxCustomers, currCustomers);
    }

    cout << maxCustomers << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}