#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n < 4){
        cout << "NO SOLUTION\n";
        return 0;
    }  

    // Middle value stays at starting position, 
    // after that, we just print smallest -> biggest -> ...
    // shake, shake!
    cout << (n/2)+1;
    int l = 1; 
    int r = n;
    int qtd = 1;
    while(true){
        cout << " " << l;
        qtd++;
        if(qtd == n) break;
        
        cout << " " << r;
        qtd++;
        if(qtd == n) break;

        l++; r--;
    }

    cout << endl;


    return 0;
}
