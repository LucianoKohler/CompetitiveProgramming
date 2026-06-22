// https://codeforces.com/group/4QT6JKdRZ8/contest/525314/problem/I
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<ll>qtdBitsOn(31, 0);

void solve(){
    int n; cin >> n;
    vector<ll>nums(n, 0);
    int groups = 1;
    ll sum = 0;
    int currSum = 0;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];

        if(nums[i] & currSum){ // Wasting bits, new group
            groups++; 
            currSum = nums[i];
        }else{
            currSum += nums[i];
        }
    }

    cout << sum << " " << groups << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
   solve();

    return 0;
}

/*
5
4 1 2 1 3

100 001 010 001 011

0001
0011
0100
1000
0010

*/