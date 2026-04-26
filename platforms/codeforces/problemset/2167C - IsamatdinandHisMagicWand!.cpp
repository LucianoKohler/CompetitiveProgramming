#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n; cin >> n;

  while(n--){
    int m; cin >> m;
    ll nums[m]; 
    bool parity[m]; // 0 for even, 1 for odd
    for(int i = 0; i < m; i++){
        cin >> nums[i];
        if(nums[i] % 2 == 0){
            parity[i] = 0;
        }else{
            parity[i] = 1;
        }
    }
    
    int qtdOdds = 0;
    int qtdEven = 0;
    for(int i = 0; i < m; i++){
        if(parity[i] == 0){
            qtdEven++;
        }else{
            qtdOdds++;
        }
    }
    
    if(qtdOdds > 0 && qtdEven > 0){
        sort(nums, nums+m);    
    }
    
    for(int i = 0; i < m; i++){
            cout << nums[i] << " ";
    }
    
    cout << endl;
  }
}