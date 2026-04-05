# https://www.hackerrank.com/challenges/collections-counter/

from collections import Counter

# Number os shoes
x = int(input())

# Each shoe's size
arr = [int(i) for i in input().split(" ")]

counter = Counter(arr)
profit = 0

# Number os customers
n = int(input())

for _ in range (n):
    # Shoe purchased and the price paid
    shoe, price = [int(i) for i in input().split(" ")]
    if counter[shoe] > 0:
        profit += price
        counter[shoe] -= 1

print(profit)