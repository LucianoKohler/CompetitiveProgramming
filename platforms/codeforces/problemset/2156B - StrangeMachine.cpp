// https://codeforces.com/problemset/problem/2156/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
        int qtdM, qtdQ;
        cin >> qtdM >> qtdQ;
        
        string machines;
        cin >> machines;
        
        bool hasB = false;
        for(char c : machines){
            if(c == 'B'){
                hasB = true;
            }
        }
        
        if(!hasB){
            while(qtdQ--){
                int num; 
                cin >> num; 
                cout << num << endl;
            }
        }else{
            
            while(qtdQ--){
                int num;
                cin >> num;
                int i = 0;
                int qtdMoves = 0;
                
                while(num != 0){
                    if(i == qtdM){i=0;}
                    
                    if(machines[i] == 'A'){ num-=1; }
                    else                  { num = floor(num/2.0); }
                    
                    qtdMoves++;
                    i++;
                }
                cout << qtdMoves << endl;
            }
        }
    }

    return 0;
}