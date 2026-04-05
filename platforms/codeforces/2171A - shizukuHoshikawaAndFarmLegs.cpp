// https://codeforces.com/contest/2171/problem/A
#include <bits/stdc++.h>
 
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        int ways = 1;
        if(a%2==1){
            cout << "0\n";
        }else{
            while(a >= 4){
                ways++;
                a-=4;
            }
            cout << ways << endl;
        }
    }
}