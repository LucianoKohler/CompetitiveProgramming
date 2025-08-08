#include <iostream>
using namespace std;

int main()
{
    int biggest=1, actual=0;
    char c, lastchar = ' ';
    
    while(cin >> c){
        if(c == lastchar){
            actual++;
            if(actual > biggest){
                biggest = actual;
            }
        }else{
            lastchar = c;
            actual = 1;
        }
    }
    
    cout << biggest << endl;
    return 0;
}