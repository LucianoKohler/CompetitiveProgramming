# https://leetcode.com/problems/string-to-integer-atoi/

class Solution:
    def myAtoi(self, s: str) -> int:
        num = 0
        sign = 1

        i = 0

        # Removendo trailing spaces
        while i < len(s) and s[i] == ' ':
            i+=1

        # Se não há valores
        if i == len(s):
            return 0
        
        # Considerando + e -
        if s[i] == '-':
            sign = -1
            i+=1
        elif s[i] == '+':
            i+=1

        # Somando o número
        while i < len(s):
            if s[i] in '0123456789':
                num*=10
                num+= int(s[i])
                i+=1
            else:
                break
        
        # Multiplicando por -1 se for negativo
        num *= sign

        # Arredondando para o 32bit mais próximo
        if num > 2**31 - 1:
            num = 2**31 - 1
        if num < -2**31:
            num = -2**31
        
        return num