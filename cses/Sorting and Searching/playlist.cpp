// https://cses.fi/problemset/task/1141/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<ll> songs;
  while(n--){
    ll song;
    cin >> song;
    auto it = find(songs.begin(), songs.end(), song);
    if(it == songs.end()){
      songs.push_back(song);
    }
  }

  cout << songs.size();
}