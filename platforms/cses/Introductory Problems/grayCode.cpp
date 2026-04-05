// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int num = 0;
    size_t n; cin >> n;

    ll limit = (n*n)-1;
    while(num <= limit){
        bitset<16> bit(num);
        num++;
        // tudo errado
    }
} 
