import sys

N, K = map(int, sys.stdin.readline().split())
items = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[-1 for _ in range(K + 1)] for _ in range(N)]


def recur(index, weight):
    global items, dp

    if weight > K:
        return -100001
    if index == N:
        return 0
    if dp[index][weight] > -1:
        return dp[index][weight]

    w, v = items[index]
    dp[index][weight] = max(recur(index + 1, weight + w) + v, recur(index + 1, weight))
    return dp[index][weight]


recur(0, 0)
max_value = 0
for idx in dp:
    max_value = max(max_value, max(idx))
print(max_value)
