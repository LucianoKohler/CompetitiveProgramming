# https://leetcode.com/problems/coin-change/description/

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coinsToSumTo = [2**32] * (amount+1)
        coinsToSumTo[0] = 0

        for i in range(1, amount+1):
            best = 2**32
            for coin in coins:
                if i-coin >= 0:
                    best = min(coinsToSumTo[i-coin]+1, best)
            
            coinsToSumTo[i] = best

        if coinsToSumTo[amount] == 2**32: return -1
        return coinsToSumTo[amount]