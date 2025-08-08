#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n; cin >> n;
    if(n == 0){
        cout << 0 << endl;
    }else{
        cout << ceil(n/4) -1 << endl;
        return 0;
    }
}