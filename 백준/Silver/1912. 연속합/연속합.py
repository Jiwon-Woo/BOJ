import sys

n = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))

dp = [0 for _ in range(n + 1)]

for i in range(n):
    dp[i + 1] = max(dp[i] + seq[i], seq[i])

print(max(dp[1:]))