// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mx = 1e5+3;
const ll inf = 1e18;

int n, m; 
int parent[mx];
int sizes[mx];
int maxSize = 0;
int qtdComponents = n;

int find(int num);
void unionDSU(int num, int targ);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    qtdComponents = n;

    for(int i = 1; i <= n; i++){
        sizes[i] = 1;
        parent[i] = i;
    }
    maxSize = 1;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        unionDSU(a, b);

        cout << qtdComponents << " " << maxSize << endl;
    }
}


int find(int num){
    if(parent[num] == num){
        return num;
    }

    return find(parent[num]);
}

void unionDSU(int num, int targ){
    int a = find(num);
    int b = find(targ);
    if(a == b) return;
    qtdComponents--;

    if(a < b) swap(a,b);
    parent[b] = a;
    sizes[a] += sizes[b];

    if(sizes[a] > maxSize){
        maxSize = sizes[a];
    }
}