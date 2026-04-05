// https://cses.fi/problemset/task/1073/
// Primeiro código a usar iterators

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> towers;

int main()
{
    int n; cin >> n;
    bool placed = false;
    
    while(n--){
        ll cube; cin >> cube;

        // Valor imediatamente superior, como a lógica do código mantém os
        // valores ordenados, sempre achamos o lugar otimizado para o cube
        auto it = upper_bound(towers.begin(), towers.end(), cube);
        
        if(it == towers.end()){
            towers.push_back(cube);
        }else{
            *it = cube;
        }

    }
    
    cout << towers.size() << endl;
}