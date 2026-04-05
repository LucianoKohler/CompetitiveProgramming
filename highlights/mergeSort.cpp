#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& leftV, vector<int>& rightV, vector<int>& v){
    int i = 0, l = 0, r = 0; 
    int lSize = leftV.size();
    int rSize = rightV.size();
    
    // Comparações estilo sliding window para encher o array ordenadamente
    while(l < lSize && r < rSize){
        if(leftV[l] < rightV[r]){
            v[i] = leftV[l];
            l++;
        }else{
            v[i] = rightV[r];
            r++;
        }
        i++;
    }

    // Whiles para pegar os restos (se L acabou antes de R, por exemplo)
    while(l < lSize){
        v[i] = leftV[l];
        l++;
        i++;
    }

    while(r < rSize){
        v[i] = rightV[r];
        r++;
        i++;
    }
}

void mergeSort(vector<int>& v){
    int n = v.size();
    if(n <= 1) return; // Caso base

    vector<int> leftArr;
    vector<int> rightArr;

    for(int i = 0; i < n/2; i++) leftArr.push_back(v[i]);
    for(int i = n/2; i < n; i++) rightArr.push_back(v[i]);

    // Recursividade
    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, v);
}


int main(){
    vector<int> v = {1, 5, 8, 2, 6, 4, 7, 3};

    for(int i = 0; i < v.size(); i++){ cout << v[i] << " ";}
    mergeSort(v); cout << "\n";
    for(int i = 0; i < v.size(); i++){ cout << v[i] << " ";}
}