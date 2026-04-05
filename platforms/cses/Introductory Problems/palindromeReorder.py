# https://cses.fi/problemset/task/1755/

from collections import Counter
import sys

n = input()
counter = Counter(n)

if len(n) % 2 == 0:
    oddsLimit = 0
else:
    oddsLimit = 1

qtdOdds = 0
oddChar = ''
for char in counter:
    if counter[char] % 2 != 0:
        qtdOdds += 1
        oddChar = char
        if qtdOdds > oddsLimit:
            print("NO SOLUTION")
            sys.exit()

string = [''] * len(n)
i = 0
j = len(n) - 1

for char in sorted(counter.keys()):
    count = counter[char]

    if char == oddChar:
        string[len(n)//2] = oddChar
        count -= 1

    for _ in range(count // 2):
        string[i] = char
        string[j] = char
        i += 1
        j -= 1

print("".join(string))
