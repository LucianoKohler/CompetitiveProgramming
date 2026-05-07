// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    if(n == 1) {
        cout << "0\n1\n";
        return 0;
    }

    // Using the mirror method, we add a defined sequence, and if we want
    // to increase it (+1 bit), we just duplicate the sequence reversed
    // and add 0 for the original elements and 1 to the reversed ones
    vector<string>gray;

    // Base case
    gray.push_back("00");
    gray.push_back("01");
    gray.push_back("11");
    gray.push_back("10");

    // To increase size
    for(int i = 3; i <= n; i++){
        vector<string>clone = gray;
        
        // Add the mirror, then fix the previous sequence
        for(int j = clone.size()-1; j >= 0; j--){
            gray.push_back("1" + clone[j]);
        }
        for(int j = 0; j < gray.size()/2; j++){
            gray[j] = "0" + gray[j];
        }

    }

    for(string s : gray){
        cout << s << "\n";
    }
} 
