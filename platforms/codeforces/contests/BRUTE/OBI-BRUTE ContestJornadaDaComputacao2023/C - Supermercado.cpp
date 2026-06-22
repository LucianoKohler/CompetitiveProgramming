// https://codeforces.com/group/4QT6JKdRZ8/contest/473126/problem/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
map<int, int>divisors;

void solve(){
    int n; cin >> n;
    vector<int>freq(mx, 0);
    int maxV = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        freq[num]++;
        maxV = max(maxV, num);
    }

    int maxPerformance = 0;
    int melhorNota = 2;
    for(int nota = 2; nota <= maxV; nota++){

        int performance = 0;
        for(int multiplo = nota; multiplo <= maxV; multiplo += nota){
            performance += freq[multiplo];
        }

        if(performance > maxPerformance){
            maxPerformance = performance;
            melhorNota = nota;
        }
    }

    cout << maxPerformance << "\n" << melhorNota << "\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}