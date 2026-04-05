# https://leetcode.com/problems/add-binary/

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = int(a)
        b = int(b)

        c = list(str(a+b))

        # 2021 -> 10101

        for i in range(len(c)-1, 0, -1):
            if c[i] == '2' or c[i] == '3':
                c[i] = str(int(c[i])%2)
                c[i-1] = str(int(c[i-1]) + 1)


        if c[0] == '2' or c[0] == '3':
            c[0] = str(int(c[0])%2)
            c.insert(0, '1')

        return "".join(c)

        