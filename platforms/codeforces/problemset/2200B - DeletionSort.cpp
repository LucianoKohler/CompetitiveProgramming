// https://codeforces.com/contest/2200/problem/B

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){

        int n; cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int isSorted = true;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                isSorted = false;
                break;
            }

            // if(a[i-2] > a[i-1]){ // Muito ruim
            //     break;
            // }else{
            //     a.erase(a.begin() + i);
            // }
        }

        if(isSorted){
            cout << n << "\n";
        }else{
            cout << "1\n";
        }
    }
    return 0;
}