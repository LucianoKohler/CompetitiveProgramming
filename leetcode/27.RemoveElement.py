# https://leetcode.com/problems/remove-element/

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        
        # Ordem reversa para não ter index out of range ao remover valores
        for i in range(len(nums)-1, -1, -1): 
            if nums[i] == val:
                nums.pop(i)
            else:
                k+=1

        return k
            