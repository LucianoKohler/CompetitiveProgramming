// https://codeforces.com/group/9CNwiex6Ir/contest/693848/problem/B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5;

void solve(){
    string sa, sp; cin >> sa >> sp;
    vector<ll>freqA(26, 0);
    vector<ll>freqP(26, 0);
    ll sizeA = sa.size(), sizeP = sp.size();
    for(char c : sa) freqA[c-'a']++;
    for(char c : sp) freqP[c-'a']++;

    int q; cin >> q;
    
    while(q--){
        int type; cin >> type;
        if(type == 1){ // Add to Ada

            ll qtd; string s;
            cin >> qtd >> s;
            for(char c : s) freqA[c-'a'] += qtd;
            sizeA += s.size() * qtd;
            
        }else if(type == 2){ // Add to Py
            ll qtd; string s;
            cin >> qtd >> s;
            for(char c : s) freqP[c-'a'] += qtd;
            sizeP += s.size() * qtd;

        }else{ // Print winner

            bool draw = false;
            int aWalked = 0, pWalked = 0;
            for(int i = 0; i < 26; i++){

                if(freqA[i] > freqP[i]){
                    if(pWalked+freqP[i] >= sizeP){ // If P is over or will be over this turn
                        cout << "PY\n";
                    }else{
                        cout << "ADA\n";
                    }
                    break;
                } 

                if(freqA[i] < freqP[i]){
                    if(aWalked+freqA[i] >= sizeA){ // If A is over or will be over this turn
                        cout << "ADA\n";
                    }else{
                        cout << "PY\n";
                    }
                    break;
                }

                aWalked+= freqA[i];
                pWalked+= freqP[i];

                if(i == 25) draw = true;
            }
            if(draw) cout << "EMPATE\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

    return 0;
}
