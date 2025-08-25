// https://judge.beecrowd.com/en/problems/view/1087

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int xS, yS, xF, yF;
    bool cond = false;
    
    while(!cond){
        cin >> xS >> yS >> xF >> yF;
        
        if(!xS && !yS && !xF && !yF) { cond = true; continue; }
        
        if(xS == xF && yS == yF) { cout << "0\n"; continue; }
        
        if(xS == xF || // Horizontal
           yS == yF || // Vertical
           xS-yS == xF-yF || yS-xS == yF-xF || // Main Diagonal
           xS+yS == xF+yF // Secon. Diagonal
           ){ cout << "1\n"; continue; }
        
        cout << "2\n"; continue;
    }
    return 0;
}