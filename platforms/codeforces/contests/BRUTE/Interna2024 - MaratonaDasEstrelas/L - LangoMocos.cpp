// // https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/L
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<int>adj[mx];
vector<int>whichBag(mx, 0);

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(n == 1){
        cout << "POSSIVEL\n";
        cout << "1 0\n";
        cout << "1\n\n";
        return;
    }

    vector<int>b1, b2;
    stack<pair<int, int>> s; // element, which bag

    bool impossible = false;
    for(int i = 1; i <= n; i++){
        if(whichBag[i] > 0) continue; // already in bag

        s.push({i, 1});

        while(!s.empty()){
            int v = s.top().first;
            int bag = s.top().second;
            s.pop();

            if(whichBag[v] > 0) continue; // Processed

            if(bag == 1) b1.push_back(v);
            else         b2.push_back(v);
            whichBag[v] = bag;

            if(impossible){
                cout << "IMPOSSIVEL\n"; 
                return;
            }
            
            for(auto c : adj[v]){
                if(bag == 1){
                    if(whichBag[c] == 0){
                        s.push({c, 2});
                    }else if(whichBag[c] == 1) impossible = true;
                }else{
                    if(whichBag[c] == 0){
                        s.push({c, 1});
                    }else if(whichBag[c] == 2) impossible = true;
                }
            }
        }
    }

    if(impossible){
        cout << "IMPOSSIVEL\n";
    }else{
        cout << "POSSIVEL\n";
        cout << b1.size() << " " << b2.size() << "\n";
        for(int num : b1) cout << num << " ";
        cout << "\n";
        for(int num : b2) cout << num << " ";
        cout << "\n";
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}
