// https://codeforces.com/contest/2162/problem/B

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
  size_t l = 0;
  size_t r = s.length();
  while(l < r){
    if(s[l] == s[r]){
      l++;
      r--;
    }else{
      return 0;
    }
  }

  return 1;
}

int main()
{
    int n; cin >> n;
    while(n--){
      int m; cin >> m;
      string s; cin >> s;
      cout << isPalindrome(s);
    }
    
    return 0;
}