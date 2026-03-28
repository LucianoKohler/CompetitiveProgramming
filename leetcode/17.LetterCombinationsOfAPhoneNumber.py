# Note that len(digits) <= 4 always, so we do it the dumb way =)

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letters ={
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }

        ans = []

        if len(digits) == 1:
            ans += [a for a in letters[digits[0]]]

        elif len(digits) == 2:
            for l1 in letters[digits[0]]:
                for l2 in letters[digits[1]]:
                    ans.append(l1+l2)

        elif len(digits) == 3:
            for l1 in letters[digits[0]]:
                for l2 in letters[digits[1]]:
                    for l3 in letters[digits[2]]:
                        ans.append(l1+l2+l3)

        elif len(digits) == 4:
            for l1 in letters[digits[0]]:
                for l2 in letters[digits[1]]:
                    for l3 in letters[digits[2]]:
                        for l4 in letters[digits[3]]:
                            ans.append(l1+l2+l3+l4)
        return ans