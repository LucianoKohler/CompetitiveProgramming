#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const unsigned long long mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
  ull n= 0;
  cin >> n;

  ull v = binpow(2, n, mod);
  
  printf("%llu", v);
  
  return 0;
}