#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        vector<int>seq(3*a, 0);

        // 1 small, 2 big
        int maxNum = 3*a;
        int minNum = 1;
        for(int j = 0; j < 3*a; j+=3){
            seq[j] = minNum;
            seq[j+1] = maxNum;
            seq[j+2] = maxNum-1;

            minNum++;
            maxNum-=2;
        }

        for(int j = 0; j < 3*a; j++){
            cout << seq[j] << " ";
        }
        
        cout << "\n";
    }

    return 0;
}