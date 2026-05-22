// https://codeforces.com/group/4QT6JKdRZ8/contest/518512/problem/E     
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    int n; cin >> n;
    int qtdEven = 0, qtdOdd = 0;
    vector<int>evenOrOdd(n, -1);
    vector<int>even;
    vector<int>odd;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a%2==0){
            even.push_back(a);
            evenOrOdd[i] = 0;
        }else{
            odd.push_back(a);
            evenOrOdd[i] = 1;
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int evenI = 0, oddI = 0;
    int num = 0;
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(evenOrOdd[i] == 0){
            if(even[evenI] >= num){
                num = even[evenI];
                evenI++;
            }else{
                ok = false;
                break;
            }
        }else{
            if(odd[oddI] >= num){
                num = odd[oddI];
                oddI++;
            }else{
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
    
}

/*
11 3 15 3 2
2 3 3 11 15
*/

// 10 7 8 1 2 3
// 1 2 3 7 8 10

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}