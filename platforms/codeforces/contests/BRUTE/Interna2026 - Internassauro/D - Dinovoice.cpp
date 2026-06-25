// https://codeforces.com/gym/106601/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;
vector<vector<int>>nums(40, vector<int>(mx, 0));


void solve(){
    double n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[0][i];
    }

    int maxDisc = 0;
    int level = 0;
    int auxI = 0;
    while(n > 1){

        for(int i = 0; i < n; i += 2){
            if(nums[level][i] == 0) break;
            if(nums[level][i+1] == 0){
                nums[level+1][auxI] = nums[level][i];
                auxI++;
            }else{
                nums[level+1][auxI] = max(nums[level][i], nums[level][i+1]);
                maxDisc = max(maxDisc, abs(nums[level][i] - nums[level][i+1]));
                auxI++;
            }
        }

        level++;
        auxI = 0;
        n = ceil(n/2.0);
    }

    cout << maxDisc << "\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}