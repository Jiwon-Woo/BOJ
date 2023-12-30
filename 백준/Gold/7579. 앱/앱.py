import sys

N, M = map(int, sys.stdin.readline().split())
memories = list(map(int, sys.stdin.readline().split()))
costs = list(map(int, sys.stdin.readline().split()))
max_cost = sum(costs)
min_cost = max_cost + 1
dp = [[0 for _ in range(max_cost + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(max_cost + 1):
        if (j - costs[i - 1] >= 0):
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costs[i - 1]] + memories[i - 1])
        else:
            dp[i][j] = dp[i - 1][j]
        
        if dp[i][j] >= M:
            min_cost = min(min_cost, j)

print(min_cost)
