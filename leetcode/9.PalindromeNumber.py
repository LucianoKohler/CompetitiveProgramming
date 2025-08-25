# https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        return True if s == s[::-1] else False