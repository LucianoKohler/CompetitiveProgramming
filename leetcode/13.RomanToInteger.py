# https://leetcode.com/problems/roman-to-integer/

class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        vals = {
            'CM' : 900,
            'CD' : 400,
            'XC' : 90,
            'XL' : 40,
            'IX' : 9,
            'IV' : 4,
            'M' : 1000,
            'D' : 500,
            'C' : 100,
            'L' : 50,
            'X' : 10,
            'V' : 5,
            'I' : 1
        }
        while len(s) > 0:
            sEvaluated = ""

            if len(s) == 1: 
                sEvaluated = s
                s = ''
            else:
                if s[0:2] in vals:
                    sEvaluated = s[0:2]
                    s = s[2:]
                else:
                    sEvaluated = s[0]
                    s = s[1:]
            
            sum += vals[sEvaluated]
        return sum
