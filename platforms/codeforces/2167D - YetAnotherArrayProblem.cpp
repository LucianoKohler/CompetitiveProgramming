#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;

  while(n--){
    int m; cin >> m;
    ll nums[m];


    for(int i = 0; i < m; i++){ cin >> nums[i]; }
    
    for(int i = 2;; i++){
        bool found = false;
        for(int j = 0; j < m; j++){
            if(gcd(i, nums[j]) == 1){
                cout << i << endl;
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
  }
}