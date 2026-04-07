#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 2e5+5

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;

    vector<pair<ll, ll>>schedule(n, {0, 0});
    // Ending time comes first for sorting
    for(int i = 0; i < n; i++) cin >> schedule[i].second >> schedule[i].first;

    sort(schedule.begin(), schedule.end());

    // Get always the event that ends as early as possible
    ll currentTime = 0;
    int qtdEvents = 0;
    for(auto event : schedule){
        if(currentTime <= event.second){
            currentTime = event.first;
            qtdEvents++;
        }
    }

    cout << qtdEvents << "\n";
    return 0;
}
/*
3 5
5 8
4 9
*/