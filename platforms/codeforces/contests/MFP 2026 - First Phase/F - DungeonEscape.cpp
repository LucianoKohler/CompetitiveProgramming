// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/F
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

// Fazer O(100^100) = O(1)

void solve(){
    int n, k; cin >> n >> k;
    vector<double>sides(n, 0);
    for(int i = 0; i < n; i++){
        cin >> sides[i];
    }

    double probNotPassing = 1;
    for(int i = 0; i < n; i++){
        double failingSides = 0;
        for(int j = 1; j <= sides[i]; j++){
            if(j < k){
                failingSides++;
            }
        }

        failingSides /= sides[i];
        probNotPassing *= failingSides;
    }
    cout << fixed << setprecision(14) <<  1.0-probNotPassing << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
