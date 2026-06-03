# Prefix Sum

Complexity: 
- Pre-processing: **O(n)**
- Query: **O(1)**
- Memory: **O(n)**

---

Given an array of static values (they never change), for example:

`nums[n] = { 3, 2, 4, 5, 1, 1, 5, 3 }`

If we want to get the sum of values between the positions "a" and "b" from the array, we can, for each sum, loop through the array and sum each value cumulatively and save them on a **prefix** array, where each position **i** saves the sum from element 1 to **i**. Take a look:

| nums | 3 | 2 | 4 | 5  | 1  | 1  | 5  | 3  |
|------|---|---|---|----|----|----|----|----|
| pref | 3 | 5 | 9 | 14 | 15 | 16 | 21 | 24 |

With this vector, we can efficiently calculate the sum of interval "a" to "b" by returning `pref[b-1] - pref[a-2]` in O(1).


### Related Problem and Algorithm's Code
```cpp
// https://cses.fi/problemset/1646/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int n, queries; // Size of the array and number of queries
    cin >> n >> queries;
    ll nums[n];
    ll pref[n];

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(i==0){
          pref[i] = nums[i];
        }else{
          pref[i] = pref[i-1] + nums[i];
        }
    }
    
    while(queries--){
        int a, b; // Return sum from "a" to "b"
        cin >> a >> b;
        if (a == 1){
          cout << pref[b-1] << endl;
        }else{
          cout << pref[b-1] - pref[a-2] << endl;
        }
    }
 
    return 0;
}
```