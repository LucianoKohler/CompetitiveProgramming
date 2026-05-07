#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const ll mx = 2e5+5;
ll n; 

void solve(){
    if(((n*(n+1))/2)%2 == 0) { // If the sum of 1..n is divisible by 2
        ll targSum = (n*(n+1))/4;
        vector<ll>a;
        ll sumA = 0, sumB = 0;
        vector<ll>b;
        
        for(ll i = n; i > 0; i--){
            if(i <= targSum){
                a.push_back(i);
                targSum-=i;
                sumA+=i;
            }else{
                b.push_back(i);
                sumB+=i;
            }
        }
        
        cout << "YES\n";
        cout << a.size() << "\n";
        for(ll num : a) cout << num << " ";
        cout << "\n" << b.size() << "\n";
        for(ll num : b) cout << num << " ";
        cout << "\n";
    }else{
        cout << "NO\n";
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    solve();

    return 0;
}
