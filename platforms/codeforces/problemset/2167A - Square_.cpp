// https://codeforces.com/contest/2167/problems/D

#include<bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;

  while(n--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b && c == d && a == c){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}