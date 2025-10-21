// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int qtdSteps = 0;

int pot10(int exp){
  int m = 1;
  for(int i = 0; i < exp; i++){
    m*=10;
  }
  return m;
}

void removingDigits(int n){
  if(n <= 0) { cout << qtdSteps << endl; return; }

  int qtdDigits = 0;
  int nCopy = n;
  
  while(nCopy > 0){
    qtdDigits++;
    nCopy/=10;
  }

  int highest = n%10;
  for(int i = 1; i < qtdDigits; i++){
    int num = n;
    num /= (pot10(i));
    num %=10;
    if(num > highest){
      highest = num;
    }
  }
  qtdSteps++;
  removingDigits(n-highest);
}

int main(){
  cin.tie(nullptr);
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  removingDigits(n);
}