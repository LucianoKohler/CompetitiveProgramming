// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      /* Em resumo, não removemos os valores, apenas colocamos
      os valores únicos no início e dizemos para o leitor do 
      código ir até a posição j na hora de ver o vetor único, 
      assim i "lixo" que fica após os únicos será ignorado.
      */
        if (nums.empty()) return 0;

        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};