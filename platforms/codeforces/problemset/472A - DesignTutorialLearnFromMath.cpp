// https://codeforces.com/problemset/problem/472/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

bool isPrime(int num) {
      if(num <= 1) return false;
      if (num <= 3) return true;

      if (num % 2 == 0 || num % 3 == 0)
          return false;

      for (int i = 5; i <= sqrt(num); i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;

      return true;
}

void solve(){
    int n; cin >> n;
    if(n%2 == 0){
        cout << "4 " << n-4 << "\n";
    }else{
        for(int i = 3; i <= n; i++){
            if(isPrime(i)) continue;
            if(!isPrime(n-i)){
                cout << i << " " << n-i << "\n"; 
                break;
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();

    return 0;
}

