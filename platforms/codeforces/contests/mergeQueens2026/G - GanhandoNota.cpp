// https://codeforces.com/group/4QT6JKdRZ8/contest/688925/attachments
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll modulo = 1e9+7;
const int mx = 2e5+5; // This varies!

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;

    string alunos; cin >> alunos;
    char melhorAluno = alunos[0];
    int melhorSeq = 1;
    int seq = 1;
   
    for(int i = 1; i < n; i++){
      if(alunos[i] == alunos[i-1]){
        seq++;
      }else{
        if(seq > melhorSeq){ // Se trocou mas o anterior for campeão
          melhorAluno = alunos[i-1];
          melhorSeq = seq;
        }
        seq = 1;
      }
    }

    cout << melhorSeq << "\n" << melhorAluno << endl;

    return 0;
}
