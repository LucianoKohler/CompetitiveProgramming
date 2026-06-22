// https://codeforces.com/group/4QT6JKdRZ8/contest/523074/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    ll n, money; cin >> n >> money;
    vector<pair<int, int>>movies;

    for(int i = 0; i < n; i++){
        ll price;
        cin >> price;
        movies.push_back({price, 0});
    }

    for(int i = 0; i < n; i++){
        int isRel;
        cin >> isRel;
        movies[i].second = isRel;
    }

    sort(movies.begin(), movies.end());

    ll qtdMovies = 0;
    bool usedRelease = false;
    for(int i = 0; i < n; i++){
        if(movies[i].second == 1 && usedRelease){
            continue;
        }

        if(money >= movies[i].first){
            if(movies[i].second) usedRelease = true;
            qtdMovies++;
            money -= movies[i].first;
        }
    }

    cout << qtdMovies << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}