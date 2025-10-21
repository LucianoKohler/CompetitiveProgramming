class Solution:
    @cache
    def dfs(self, start: int, target: int) -> int:
        if start == target: return 1
        if start > target:  return 0
        return self.dfs(start+1, target) + self.dfs(start+2, target)

    def climbStairs(self, n: int) -> int:
        return self.dfs(0, n)