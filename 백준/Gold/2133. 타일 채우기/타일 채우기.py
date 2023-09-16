import sys
import copy

N = int(sys.stdin.readline())

if N % 2 == 1:
    print(0)
    exit()

dp = [0 if i % 2 == 1 else 2 for i in range(N + 1)]
dp[0], dp[2] = 0, 3

# print(dp)

for i in range(4, N + 1, 2):
    for j in range(2, i, 2):
        dp[i] += dp[i - j] * (3 if j == 2 else 2)
    # print(dp)

print(dp[N])