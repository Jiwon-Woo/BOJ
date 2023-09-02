import sys

N = int(sys.stdin.readline())
house = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[0, 0, 0] for _ in range(N)]

dp[0][0] = house[0][0]
dp[0][1] = house[0][1]
dp[0][2] = house[0][2]

for index in range(1, N):
    dp[index][0] = min(dp[index - 1][1], dp[index - 1][2]) + house[index][0]
    dp[index][1] = min(dp[index - 1][0], dp[index - 1][2]) + house[index][1]
    dp[index][2] = min(dp[index - 1][1], dp[index - 1][0]) + house[index][2]

print(min(dp[N - 1]))