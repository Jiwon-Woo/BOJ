import sys
from collections import Counter

nums = map(int, sys.stdin.readline().split())
counter = dict(Counter(nums))

maxDice = 0
answer = 0

for key, value in counter.items():
    maxDice = max(maxDice, key)
    if value == 3:
        answer = 10000 + key * 1000
        break
    elif value == 2:
        answer = 1000 + key * 100
        break

if answer == 0:
    answer = maxDice * 100
    
print(answer)