//https://codeforces.com/problemset/problem/2218/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        vector<ll> nums(a, 0);

        for(int i = 0; i < a; i++) cin >> nums[i];
        
        int highest = -1;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < a; j++){
                if((nums[i] ^ nums[j]) > highest){
                    highest = (nums[i] ^ nums[j]);
                }
            }
        }
        cout << highest << "\n";

    }
    return 0;
}


/*
*/