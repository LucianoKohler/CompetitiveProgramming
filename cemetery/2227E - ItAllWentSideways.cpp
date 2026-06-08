/*
    .                           .....
    .--.    B L O C K I E R    -----...
    ...--.                . .-=---.....
     ...----==###==#####==###==-. .....
      -===###=-=#=-=####=-----##==.. ..
      -=-   .-#======##==-.--=-   .-. .
     .==  .    .###=###=-=-=- .    -..
    .==-       .--===##====--      ..-.
  ..==#-.     ==--====###===--=.  ..--..
 ..-====##===##===============--====-...
 ..-=========######======--- ...==-----.
  .-==========#####==....        =---...
....====-===#=######.           .=---.
. .-====--=#########=--.        ----=-.
...-###=========--------.     ===--..-.
..######=#===---....            ==--...
-=########===-.                      .
-=##########==--.
===#####=======--..
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9 + 7;
const int mx = 2e5 + 5; // This varies!

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        ll sum = 0;
        for (int i = 0; i < n; i++){
            cin >> nums[i];
            sum += nums[i];
        }
        if (n == 1){
            cout << 0 << "\n";
            continue;
        }

        vector<int> suf(n, 0);
        suf[n - 1] = nums[n - 1];
        sum -= suf[n - 1];
        for (int i = n - 2; i >= 0; i--){
            suf[i] = min(suf[i + 1], nums[i]);
            sum -= suf[i];
        }

        int currBlock = 1;
        int maxBlock = -1;
        for (int i = 1; i < n; i++){
            if (suf[i] == suf[i - 1]) currBlock++;
            else{
                maxBlock = max(maxBlock, currBlock);
                currBlock = 1;
            }
        }
        maxBlock = max(maxBlock, currBlock);

        cout << sum + maxBlock - 1 << "\n";
    }
    return 0;
}
