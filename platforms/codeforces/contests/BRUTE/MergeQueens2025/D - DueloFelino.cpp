// https://codeforces.com/group/4QT6JKdRZ8/contest/603077/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<int>paresLuiza;
    vector<int>imparesLuiza;
    vector<int>paresRisa;
    vector<int>imparesRisa;

    for(int i = 0; i < n; i++){
      int num; cin >> num;
      if(num%2 == 0){
        paresLuiza.push_back(num);
      }else{
        imparesLuiza.push_back(num);
      }
    }

    for(int i = 0; i < n; i++){
      int num; cin >> num;
      if(num%2 == 0){
        paresRisa.push_back(num);
      }else{
        imparesRisa.push_back(num);
      }
    }

    if(imparesRisa.size() == paresLuiza.size() && paresRisa.size() == imparesLuiza.size()){
      cout << "SIM\n";
    }else{
      cout << "NAO\n";
    }

    return 0;
}
