// https://codeforces.com/contest/2200/problem/A

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>possibleWinners(n+1, 0);
        vector<int>plates(n+1, 0);
        int sum = 0;

        for(int i = 0; i < n; i++){
            cin >> plates[i+1];
            sum += plates[i+1];
        }

        // Simulating all possibilities
        for(int i = 0; i < n; i++){

            // Clona os pratos
            vector<int> clonedPlates = plates;
            int clonedSum = sum;
            int currentPlayer = i+1;


            // When i player goes first
            while(true){
                if(clonedPlates[currentPlayer]){
                    clonedPlates[currentPlayer]--;
                    clonedSum--;
                }
                // cout << "P: " << currentPlayer << ", C: " << clonedPlates[currentPlayer] << "\n";

                // Player wins 
                if(!clonedSum){
                    possibleWinners[currentPlayer] = 1;
                    break;
                }
                
                currentPlayer = ((currentPlayer) % n) + 1;
            }
        }

        // Finding how many players won
        int WinnerSum = 0;
        for(auto num : possibleWinners){
            WinnerSum += num;
        }
        cout << WinnerSum  << "\n";
    }

    return 0;
}