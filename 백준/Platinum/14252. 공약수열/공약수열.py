import sys
import math

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
a.sort()

answer = 0
for i in range(1, n):
    if math.gcd(a[i - 1], a[i]) != 1:
        for j in range(a[i - 1], a[i] + 1):
            if math.gcd(j, a[i - 1]) == 1 and math.gcd(j, a[i]) == 1:
                answer += 1
                break
            if j == a[i]:
                answer += 2

print(answer)