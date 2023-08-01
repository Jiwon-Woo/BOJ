import sys
import math

a, b = map(int, sys.stdin.readline().split())
multi = a * b

factors = []
for i in range(a, int(multi**0.5) + 1):
    if multi % i == 0:
        factors.append([i, multi // i])

answer = [a, multi // a]
for factor in factors:
    x, y = factor
    if math.gcd(x, y) == a and math.lcm(x, y) == b:
        if x + y < sum(answer):
            answer = [x, y]

print(*answer)
