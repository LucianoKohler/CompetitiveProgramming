#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    int n =0;
    cin >> n;
    
    if((n*(n+1))%4 == 0){
        cout << "YES" << endl;
        
        ull targSum = (1ULL * n*(n+1))/4;
        vector<int> g1;
        vector<int> g2;
        
        for(int i = n; i > 0; i--){
            
            if(targSum >= (ull)i){
                g1.push_back(i);
                targSum-=i;
            }else{
                g2.push_back(i);
            }
            
        }
        
        cout << g1.size() << endl;
        for(int num : g1){
            cout << num << " ";
        }
        
        cout << endl << g2.size() << endl;
        for(int num : g2){
            cout << num << " ";
        }

    }else{
        cout << "NO";
    }
  
  return 0;
}