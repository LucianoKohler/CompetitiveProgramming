# https://leetcode.com/problems/reverse-integer/

class Solution:
    def reverse(self, x: int) -> int:
        sig = 1
        if x < 0:
            x = -x
            sig = -1
        s = str(x)
        s = s[::-1]
        x = int(s) * sig
        if(abs(x) > 2**31):
            return 0
        return x